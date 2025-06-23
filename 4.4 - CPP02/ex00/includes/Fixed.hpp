#ifndef FIXED_HPP
#define FIXED_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>

/*-------------- CLASS --------------*/

/*
** int value : entier brut qui stocke la valeur multipliée
** int fractionalBits : nombre de bits (1 << 8 = 256)
** getRawBits : retourne la valeur brute de value sans conversion
** setRawBits : modifie value avec une valeur brute
*/

class Fixed
{
private:
	int	value;
	static const int	fractionalBits = 8;

public:
	Fixed(); // Constructeur par défaut
	Fixed(const Fixed &other); // Constructeur de recopie
	Fixed &operator=(const Fixed &other); // Opérateur d'affectation =
	~Fixed(); // Destructeur

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif