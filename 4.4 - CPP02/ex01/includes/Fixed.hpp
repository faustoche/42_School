#ifndef FIXED_HPP
#define FIXED_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>
#include <cmath>

/*-------------- CLASS --------------*/

/*
** int value : entier brut qui stocke la valeur multipliée
** int fractionalBits : nombre de bits (1 << 8 = 256)
** getRawBits : retourne la valeur brute de value sans conversion
** setRawBits : modifie value avec une valeur brute
** toFloat: convertit la valeur en virgule fixe en nombre à virgule flottante
** toInt : convertit la valeur virgule fixe en nombre entier
*/

/*
** Classe pour un nombre à virgule fixe. Il stocke un entier (value)
** 8 bits car c'est ce qui est le plus précis 
** Exemple : si value = 256, alors = 1 car 256/2 exposant 8 = 1
**
*/

class Fixed
{
private:
	int	value;
	static const int	fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	Fixed (int const convert);
	Fixed (float const convert);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

/*
** std::ostream : type général de tous les flux de sortie. Fait référence à un flux de sortie (std::cout)
** operator<< : nom de la fonction surchargé. On peut redéfinir des opérateurs comme des fonctions
** std::ostream & : le flux dans lequel on ecrit (cout)
*/

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif