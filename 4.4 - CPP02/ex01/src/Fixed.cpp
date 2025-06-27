#include "../includes/Fixed.hpp"

/*-------------- CONSTRUCTORS --------------*/

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		value = other.value;
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* 
** Décale l'entier vers la gauche de 8 bits
** Fixed(10) -> value = 10 << 8 = 2560 -> soit 10
*/

Fixed::Fixed (int const n) {
	std::cout << "Int constructor called" << std::endl;
	this->value = n << fractionalBits;
}

/* On multiplie par 256 (2^8) puis on arrondi avec roundf pour être plus précis */

Fixed::Fixed (float const n) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << fractionalBits));
}

/*-------------- FUNCTIONS --------------*/

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

/* 
** Converti value en float
** Si value = 10860 -> 10860 / 256 = 42,42
*/

float	Fixed::toFloat(void) const {
	return ((float)value / (1 << fractionalBits));
}

/*
** Converti en int et ignore la partie de la fraction
** Si value = 10860 -> 10860 >> 8 = 42
*/

int	Fixed::toInt(void) const {
	return (value >> fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return (out);
}