#ifndef FIXED_HPP
#define FIXED_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>

/*-------------- CLASS --------------*/

class Fixed
{
private:
	int	value; // entier brut qui stocke la valeur multipliée
	static const int	fractionalBits = 8; // nombre de bits (1 << 8 = 256)

public:
	Fixed(); // Constructeur par défaut - permet d'initialisé value à 0
	Fixed(const Fixed &other); // Constructeur de recopie (copie un autre objet fixed)
	Fixed &operator=(const Fixed &other); // Opérateur d'affectation =
	~Fixed(); // S'exécute quand l'objet est détruit (copie les données de x dans y)

	int		getRawBits(void) const; // retourne la valeur brute de value sans conversion
	void	setRawBits(int const raw); // modifie value avec une valeur brute
};

#endif