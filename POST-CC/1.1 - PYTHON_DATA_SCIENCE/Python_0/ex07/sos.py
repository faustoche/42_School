import sys

NESTED_MORSE = {
	" ": "/ ",
	"A": ".- ", "B": "-... ", "C": "-.-. ", "D": "-.. ",
	"E": ". ", "F": "..-. ", "G": "--. ", "H": ".... ",
	"I": ".. ", "J": ".--- ", "K": "-.- ", "L": ".-.. ",
	"M": "-- ", "N": "-. ", "O": "--- ", "P": ".--. ",
	"Q": "--.- ", "R": ".-. ", "S": "... ", "T": "- ",
	"U": "..- ", "V": "...- ", "W": ".-- ", "X": "-..- ",
	"Y": "-.-- ", "Z": "--.. ",
	"0": "----- ", "1": ".---- ", "2": "..--- ", "3": "...-- ",
	"4": "....- ", "5": "..... ", "6": "-.... ", "7": "--... ",
	"8": "---.. ", "9": "----. "

}

def main():
	if len(sys.argv) != 2:
		raise AssertionError("the arguments are bad")
	
	S = sys.argv[1]

	if not isinstance(S, str):
		raise AssertionError("the arguments are bad")
	
	## On boucle sur chaque caractères
	## On vérifie si les caractères sont alphanumérique ou espace
	for char in S:
		if not char.isalnum() and char != ' ':
			raise AssertionError("the arguments are bad")
	
	## On fait la conversion char/morse
	## On mets toutes les lettres en majuscule
	result = ""
	for char in S.upper():
		result += NESTED_MORSE[char]
	
	print(result)


if __name__ == "__main__":
	try:
		main()
	except AssertionError as error:
		print(f"AssertionError: {error}")