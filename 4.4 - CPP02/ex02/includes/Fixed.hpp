#ifndef FIXED_HPP
#define FIXED_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>
#include <cmath>

/*-------------- CLASS --------------*/

class Fixed
{
private:
	int	value;
	static const int	fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed (int const convert);
	Fixed (float const convert);
	~Fixed();
	Fixed &operator=(const Fixed &other);

	// comparaison
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// calculs
	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);

	// incrémentation/décrémentation
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif