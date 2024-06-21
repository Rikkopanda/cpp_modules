/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:05:55 by rverhoev          #+#    #+#             */
/*   Updated: 2024/04/04 12:08:25 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"
#include <limits>

#define ZERO 77
#define RIGHT 88
#define LEFT 99

/*
	perpendicularness and its orientation 
	outcome is the area
		 v1		v2
	x: | a | X | c | 
	y: | b | X | d |   = a*d - b*c = cross_product

	https://www.geogebra.org/m/d6n6rk9N

	als 2 vectors op een lijn staan dan is de cross 0
*/
Fixed	cross_product(Point const *origin, Point const *vector_1, Point const *vector_2)
{
	Fixed x = (*vector_1).getX() - (*origin).getX();
	Fixed y = (*vector_1).getY() - (*origin).getY();
	Point calc_v1(x, y);

	x = (*vector_2).getX() - (*origin).getX();
	y = (*vector_2).getY() - (*origin).getY();
	Point calc_v2(x, y);

	Fixed cross_product = (calc_v1.getX() * calc_v2.getY()) - (calc_v1.getY() * calc_v2.getX());
	// std::cout << "vector 1 xy:\t" << calc_v1.getX() << "\t" << calc_v1.getY() << std::endl;
	// std::cout << "vector 2 xy:\t" << calc_v2.getX() << "\t" << calc_v2.getY() << std::endl;
	// std::cout << (calc_v1.getX() * calc_v2.getY()) << " " << (calc_v1.getY() * calc_v2.getX()) << std::endl;
	return (cross_product);
}

static int sign_of_line(Point const *origin, Point const *point, Point const *reference)
{
	Fixed product = cross_product(origin, point, reference);
	// std::cout << "product:\t" << product << "\n" << std::endl;

	if (product > 0)
		return (RIGHT);
	else if (product < 0)
		return (LEFT);
	return (ZERO);
}

/*
	Same side technique
	https://blackpawn.com/texts/pointinpoly/

	compute the cross product of the line(A-B) vector and its reference(A-C) aka. other corner.
	check if its positive or negative(sign).
	
	compute the cross product of point with every line vector, they have the same origin.
	compare these cross products with every corresponding sign of line.
*/
bool bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	int	line_ab_sign;
	int	line_bc_sign;
	int	line_ac_sign;

	line_ab_sign = sign_of_line(&a, &b, &c);
	line_bc_sign = sign_of_line(&b, &c, &a);
	line_ac_sign = sign_of_line(&a, &c, &b);

	// std::cout << line_ab_sign << std::endl;
	// std::cout << line_bc_sign << std::endl;
	// std::cout << line_ac_sign << std::endl;

	if (sign_of_line(&a, &b, &point) != line_ab_sign || sign_of_line(&a, &b, &point) == ZERO)
		return (false);
	if (sign_of_line(&b, &c, &point) != line_bc_sign || sign_of_line(&b, &c, &point) == ZERO)
		return (false);
	if (sign_of_line(&a, &c, &point) != line_ac_sign || sign_of_line(&a, &c, &point) == ZERO)
		return (false);
	return (true);
}