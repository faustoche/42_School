Algorithm Ford-Johnson

Pour la suite de chiffres suivante :

	*** [25, 7, 35, 9, 300, 2, 12, 660, 45, 88, 57, 3, 33, 6, 99] ***

Étape 1: On créé des paires.

	*** [25, 7] [35, 9] [300, 2] [12, 660] [45, 88] [57, 3] [33, 6] *** 99 est mis de côté pour le moment

Étape 2: On trie chaque paire individuellement

	*** [7, 25] [9, 35] [2, 300] [12, 600] [45, 88] [3, 57] [6, 33] ***

Étape 3: On sépare les mins et les maxs et on envois les max, triés récursivement, dans leur tableau final

	*** min: 				[7, 9, 2, 12, 45, 3, 6] ***
	*** ordre d'insertion:	[1, 3, 2, 5,  4,  7, 6]
	*** max: 				[25, 33, 35, 57, 88, 300, 600] ***

Étape 4: On insère les mins dans le tableau final selon l'ordre de la suite de Jacobsthal
- La suite de Jacobsthal est calculé pour donner le résultat suivant : 0 1 1 3 5 11 (...)
- Au lieu d'insérer les éléments mins en passant par leurs index 0, 1, 2, 3, on utilise la suite de Jacobsthal
- Cela permet de réduire le nombre de comparaison et donc de réduire le temps d'exécution. 
- En suivant la suite de Jacobsthal : 1 3 5 11
- On insère le premier élément : 7

	*** max: [7, 25, 33, 35, 57, 88, 300, 600] ***

- On insère le troisième élément : 2

	*** max: [2, 7, 25, 33, 35, 57, 88, 300, 600] ***

- On insère le dernier élément à gauche du troisième : 9

	*** max: [2, 7, 9, 25, 33, 35, 57, 88, 300, 600] ***

- On insère le cinquième élément : 45

	*** max: [2, 7, 9, 25, 33, 35, 45, 57, 88, 300, 600] ***

- On insère le dernier élément à gauche du cinquième : 12

	*** max: [2, 7, 9, 12, 25, 33, 35, 45, 57, 88, 300, 600] ***

- On devrait insérer le onzième mais il n'y en a pas, alors on prend le dernier : 6

	*** max: [2, 6, 7, 9, 12, 25, 33, 35, 45, 57, 88, 300, 600] ***

- On insère l'élément à gauche de celui qu'on vient d'insérer : 3

	*** max: [2, 3, 6, 7, 9, 12, 25, 33, 35, 45, 57, 88, 300, 600] ***
