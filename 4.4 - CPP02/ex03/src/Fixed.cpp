#include "../includes/Fixed.hpp"

/*-------------- CONSTRUCTORS --------------*/

Fixed::Fixed() : value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		value = other.value;
	}
	return (*this);
}

Fixed::Fixed (int const n) {
	//std::cout << "Int constructor called" << std::endl;
	this->value = n << fractionalBits;
}

Fixed::Fixed (float const n) {
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << fractionalBits));
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

/*-------------- FUNCTIONS --------------*/

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

/*-------------- FUNCTIONS - COMPARISONS --------------*/

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

/*-------------- FUNCTIONS - CALCULUS --------------*/

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

/* Value et other sont déjà divisé par 256. On redivise ou remultiplie pour arriver au résultat voulu */

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

/*-------------- FUNCTIONS - INCREMENT AND DECREMENT --------------*/

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

/*-------------- FUNCTIONS TO COMPARE --------------*/

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