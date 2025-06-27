#include "../includes/Fixed.hpp"

/*
** 1. Constructeur par défault pour a = 0
** 2. Constructeur de recopie : on appelle copie + operator + getrawbits = 0
** 3. Constructeur par défault pour c = 0
** 4. Opérateur d'affectation = copy + getrawbits = 0
*/

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
