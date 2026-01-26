import sys

def even_or_odd(args) -> str:

	# On vérifie la longueur de l'argument
	assert len(args) == 2, "more than one argument is provided"

	arg = args[1]

	# On vérifie si c'est des chiffres
	assert arg.isnumeric(), "argument is not an integer"

	nb = int(arg)

	# On vérifie si c'est un nombre pair ou impair
	if ((nb % 2) == 0):
		print("I'm Even.")
	else:
		print("I'm Odd.")


# Pour éviter tout le traceback, on utilise le try except
try:
	even_or_odd(sys.argv)
except AssertionError as e:
	print("AssertionError : ", e)