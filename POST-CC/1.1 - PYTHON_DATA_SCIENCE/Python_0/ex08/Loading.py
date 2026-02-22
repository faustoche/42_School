import os
import sys

def ft_tqdm(lst: range) -> None:
	total = len(lst)
	terminal_width = os.get_terminal_size().columns

	## On calcule le pourcentage 
	for i, elem in enumerate(lst):
		percent = (i + 1) / total
		percent_display = int(percent * 100)

		## On garde une partie fixe
		## 100% -------------- | xxxx
		count_str = f"{i + 1}/{total}"
		prefix = f"{percent_display}%|"
		suffix = f"| {count_str}"

		## On calcule la largeur disponible pour la barre
		bar_width = terminal_width - len(prefix) - len(suffix) - 26

		## On construit la barre
		filled = int(percent * bar_width)
		if filled < bar_width:
			bar = "=" * filled + ">" + " " * (bar_width - filled - 1)
		else:
			bar = "=" * filled

		## On affiche le tout avec le \r pour réécrire la même ligne en boulce
		sys.stdout.write(f"\r{prefix}{bar}{suffix}")
		sys.stdout.flush()

		## Au lieu de tout calculer d'un coup, yield fait en sorte que la fonction
		## retourne tous les éléments un par un
		yield elem