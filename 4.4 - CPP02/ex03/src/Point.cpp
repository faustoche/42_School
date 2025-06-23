#include "../includes/Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(float px, float py) : x(px), y(py) {
}

Point::Point(const Point &other) : x(other.x), y(other.y) {
}

Point &Point::operator=(const Point &other) {
	(void)other;
	return (*this);
}

Point::~Point() {
}

Fixed Point::getX() const {
	return (x);
}

Fixed Point::getY() const {
	return (y);
}