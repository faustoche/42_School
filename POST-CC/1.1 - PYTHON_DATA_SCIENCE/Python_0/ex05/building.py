import sys

def main():
	""" Main function to count and identify char in a string"""


	try:
		## Si on a plus de 1 argument, on lève une exception
		if len(sys.argv) > 2:
			raise AssertionError("Cannot take more than 1 argument.")
		
		## On prend l'argument
		## On enregistre dans texte ce qui a été lu sur stdin
		elif len(sys.argv) == 1:
			print("What is the text to count?")
			text = sys.stdin.read()
		
		## Sinon
		else:
			text = sys.argv[1]
		
		## Je prends 5 variables pour stocker chaque "type de lettre"
		upper_char = 0
		lower_char = 0
		punctuation_char = 0
		space_char = 0
		digit_char = 0

		## Je lance une boucle sur chaque caractères de text
		for char in text:
			if char.isupper():
				upper_char +=1
			elif char.islower():
				lower_char +=1
			elif char.isdigit():
				digit_char +=1
			elif char.isspace():
				space_char +=1
			else:
				punctuation_char +=1

		## On affiche le contenu de notre text
		## On ajoute f pour format pour spécifier qu'une variable est dans le texte
		print(f"The text contains {len(text)} characters:")
		print(f"{upper_char} upper letters")
		print(f"{lower_char} lower letters")
		print(f"{punctuation_char} punctuation marks")
		print(f"{digit_char} digits")

	## À la fin de notre try, on lance notre exception
	except AssertionError as error:
		print(f"AssertionError: {error}")
	
	## Si jamais on fait autre chose que ctrl D
	except KeyboardInterrupt:
		print("Please, use ctrl+D to notify EOF")

# main.__doc__ = "Main function to count and identify char in a string."

## On appelle notre main
if __name__ == "__main__":
	main()