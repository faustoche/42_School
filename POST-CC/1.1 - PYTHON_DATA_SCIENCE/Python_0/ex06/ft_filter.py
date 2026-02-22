## Le build-in fonctionne comme ça : 
	## filter(fonction, liste)
	## on parcourt chaque élément de la liste, applique la fonction
	## et garde uniquement les éléments où la fonction retourne true
	## exemple: (lambda x: x > 2, [1, 2, 3, 4])
	## on garde 3 et 4 car ils sont plus grand que 2

## Utilisation de la comprehension list:
	## syntaxe: [expression for element in collection if condition]
	
def ft_filter(function, list):
	""" filter (function or none, iterable) to filter object
		Return an iterator for which function is true, if
		no function, return items that are true
	"""

	## On prends chaque item de list mais seulement si function(item) est true
	## Pour visualiser:
		## ft_filter(lambda x: x > 2, [1, 2, 3, 4])
		## item = 1 -> function(1) -> 1 > 2 -> false
		## item = 2 -> function(2) -> 2 > 2 -> false
		## item = 3 -> function(3) -> 3 > 2 -> true
		## item = 4 -> function(4) -> 4 > 2 -> true

	## On parcourt chaque item de la liste
	## On teste function(item) → est-ce que c'est true ?
	## Si oui, on garde item dans le résultat
	if function is None:
		return [item for item in list if item]
	return [item for item in list if function(item)]