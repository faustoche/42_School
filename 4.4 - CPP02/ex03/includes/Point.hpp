#ifndef _POINT_HPP_
#define _POINT_HPP_

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>
#include "Fixed.hpp"

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

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(float x, float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
	
};

/*-------------- FUNCTIONS --------------*/

bool BSP(Point const a, Point const b, Point const c, Point const point);

#endif