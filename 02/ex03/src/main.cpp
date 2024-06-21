/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:23:01 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 14:05:28 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/bsp.hpp"

/**      b
 *      / \ d
 *     /  d\
 *    /     \
 * 	 /       \
 *  a---------c
*/
int main( void )
{
	Point origin(0, 0);
	Point v1(1, -4);
	Point v2(5, 0);
	Fixed cr_product = cross_product(&origin, &v1, &v2);
	Point a(0, 0);
	Point b(8, 0);
	Point c(8, 8);
	Point point(7.95, 7.947);
	if (bsp(a, b, c, point))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
	return 0;
}

//void test()
//{
//	float	byte4_float;
//	int		integer;
//	double	byte8_float;

//	byte4_float = (double)1 / 2 + 1234567;
//	byte8_float = (float)1 / 2  + 1234567;
//	integer = 1 / 3;
//	byte4_float =std::numeric_limits<float>::min();
//	byte8_float =std::numeric_limits<double>::min();

//	byte4_float = byte4_float * 3000000000000000000;
//	byte4_float = byte4_float * 3000000000000000000;
//	byte4_float = byte4_float / 10;

//	//byte8_float << 10;

//	std::cout << integer << " " << byte4_float << " " << byte8_float << std::endl;
//	printf("int %d, float %.17f, double %.17lf\n", integer, byte4_float, byte8_float);
//}