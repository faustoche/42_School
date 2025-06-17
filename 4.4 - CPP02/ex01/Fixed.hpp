#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int	value; // entier brut qui stocke la valeur multipliée
	static const int	fractionalBits = 8; // nombre de bits (1 << 8 = 256)

public:
	Fixed(); // Constructeur par défaut - permet d'initialisé value à 0
	Fixed(const Fixed &other); // Constructeur de recopie (copie un autre objet fixed)
	Fixed &operator=(const Fixed &other); // Opérateur d'affectation =
	Fixed (int const convert);
	Fixed (float const convert);
	~Fixed(); // S'exécute quand l'objet est détruit (copie les données de x dans y)

	int		getRawBits(void) const; // retourne la valeur brute de value sans conversion
	void	setRawBits(int const raw); // modifie value avec une valeur brute
	float	toFloat(void) const; // convertit la valeur en virgule fixe en nombre a virgule flottante
	int		toInt(void) const; // convertit la valeur virgule fixe en nombre entier
};


// std::cout n'est pas un type mais un objet
// std::cout  = variable globale
// std::ostream: type général de tous les flux de sortie 
// std::ostream : retour de la fonction, référence vers un flux de sortie (std::cout)
// permet d'enchainer plusieurs << << << (cout << a << b << c);

// operator<< : nom de la fonction surchargée
// redefinir des operateurs comme des fonctions : + - << ==

// std::ostream &out, const Fixed &f
// std::ostream & : le flux dans lequel on ecrit (cout)


std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif