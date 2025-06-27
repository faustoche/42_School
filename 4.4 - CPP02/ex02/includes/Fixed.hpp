#ifndef FIXED_HPP
#define FIXED_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>
#include <cmath>

/*-------------- DEFINES --------------*/

#define RESET   	"\033[0m"
#define WHITE   	"\033[1;97m"
#define FUCHSIA 	"\033[1;38;5;201m"
#define BLUE_BRIGHT "\033[1;94m"
#define GREEN       "\033[1;32m"
#define MAGENTA     "\033[1;35m"
#define CYAN        "\033[1;36m"
#define RED 		"\033[1;91m"
#define YELLOW 		"\033[1;93m"
#define ORANGE      "\033[1;38;5;208m"
#define PINK        "\033[1;38;5;205m"
#define TURQUOISE   "\033[1;38;5;45m"
#define GOLD        "\033[1;38;5;220m"
#define CORAL       "\033[1;38;5;203m"

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