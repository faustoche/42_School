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
** setRawBits : modifie value 
** Classe pour un nombre à virgule fixe. Il stocke un entier (value)
** 8 bits car c'est ce qui est le plus précis 
** Exemple : si value = 256, alors = 1 car 256/2 exposant 8 = 1
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