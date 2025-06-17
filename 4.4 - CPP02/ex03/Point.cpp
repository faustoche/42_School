/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:33:05 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/17 23:06:49 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

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