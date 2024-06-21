/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:57:49 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include "Fixed.hpp"

class Point {
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(const float x, const float y);
		Point(Fixed& x, Fixed& y);
		Point(Point &src);
		~Point();
		Point&	operator=(Point& src);
		Fixed const getX() const;
		const Fixed getY() const;
};

#endif