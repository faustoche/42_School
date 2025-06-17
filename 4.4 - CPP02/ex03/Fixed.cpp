#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.value;
		return (*this);
}

// On multiplie par 256 (2^8)

Fixed::Fixed (int const n) {
	//std::cout << "Int constructor called" << std::endl;
	this->value = n << fractionalBits;
}

// On multiplie par 256 (2^8) puis on arrondis avec roundf pour etre + preics

Fixed::Fixed (float const n) {
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << fractionalBits));
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)value / (1 << fractionalBits));
}

int	Fixed::toInt(void) const {
	return (value >> fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return (out);
}


// comparaison
bool Fixed::operator>(const Fixed &other) const {
	return (this->value > other.value);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->value < other.value);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->value <= other.value);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->value >= other.value);
}

bool Fixed::operator==(const Fixed &other) const{
	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->value != other.value);
}

//calculs

Fixed Fixed::operator+(const Fixed &other) {
	Fixed result;
	result.setRawBits(this->value + other.value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) {
	Fixed result;
	result.setRawBits(this->value - other.value);
	return (result);
}

// Value et other sont prétraité en divisé par 256 
// donc il faut diviser ou multiplié par 256 pour arriver au résultat correct

Fixed Fixed::operator*(const Fixed &other) {
	Fixed result;
	result.setRawBits((this->value * other.value) >> fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) {
	Fixed result;
	result.setRawBits((this->value << fractionalBits) / other.value);
	return (result);
}

//incrementaiton decrementation

Fixed &Fixed::operator++() {
	++value;
	return (*this);
}

Fixed &Fixed::operator--() {
	--value;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++value;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--value;
	return (tmp);
}

// fonction de comparaison

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}