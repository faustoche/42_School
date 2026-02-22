import sys
from ft_filter import ft_filter

def main():

	""" Main function to test ft_filter """

	if len(sys.argv) != 3:
		raise AssertionError("the arguments are bad")

	## On récupère nos deux arguments
	## On vérifie qu'on reçoit bien une chaîne de caractères
	S = sys.argv[1]
	N = sys.argv[2]

	if not isinstance(S, str):
		raise AssertionError("the arguments are bad")

	## Sys renvoit des strings donc on converti N en entier
	## Si ça échoue, on lève une exception
	try:
		N = int(N)
	except ValueError:
		raise AssertionError("the arguments are bad")
	
	## On découpe la phrase en mot
	## On applique le filtre + 
	## un lambda qui conserve les mots plus longs que N
	## Lambda = fonction anonyme écrite en 1 seule ligne

	words = [word for word in S.split(' ')]
	# words = S.split(' ')
	result = ft_filter(lambda word: len(word) > N, words)
	print(result)


if __name__ == "__main__":
	try:
		main()
	except AssertionError as error:
		print(f"AssertionError: {error}")