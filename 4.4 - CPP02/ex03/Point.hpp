/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:46:28 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/17 22:32:38 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point(); // par default
	Point(float x, float y);
	Point(const Point &other); // recopie
	Point &operator=(const Point &other); // affectation
	~Point(); // destruction

	Fixed getX() const;
	Fixed getY() const;
};

Point::Point() {}
Point::~Point() {}

#endif