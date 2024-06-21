/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:03:08 by marvin            #+#    #+#             */
/*   Updated: 2024/02/13 12:03:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : x(0), y(0){if (PRINT_BOOL) {std::cout << "Point Default Constructor called" << std::endl;}}

Point::Point(const float x, const float y) : x(x), y(y){if (PRINT_BOOL) {std::cout << "Constuctor called" << std::endl;}}

Point::Point(Fixed& x, Fixed& y) : x(x), y(y){if (PRINT_BOOL) {std::cout << "Point Parameter Constructor called" << std::endl;}}

Point::Point(Point &src)
{
	if (PRINT_BOOL) {std::cout << "Point Copy Constructor called" << std::endl;}
	*this = src;
}

Point::~Point(){if (PRINT_BOOL) {std::cout << "Point Destructor called" << std::endl;}}

Point& Point::operator=(Point& src)
{
	(Fixed) this->x = src.getX();
	(Fixed) this->y = src.getY();

	if (PRINT_BOOL) {std::cout << "Point assignment operator called" << std::endl;}
	return *this;
}

const Fixed Point::getX() const
{
	return (this->x);
}

const Fixed Point::getY() const
{
	return (this->y);
}