#ifndef _POINT_HPP_
#define _POINT_HPP_

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>
#include "Fixed.hpp"

/*-------------- DEFINES --------------*/

#define RESET   "\033[0m"
#define WHITE   "\033[97m"
#define FUCHSIA "\033[38;5;201m"
#define BLUE_BRIGHT "\033[94m"
#define RED "\033[91m"
#define YELLOW "\033[93m"

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