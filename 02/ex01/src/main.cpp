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
#include "../include/Fixed.hpp"
#include <limits>
#include <cmath>

/*
	coole calculators:
	https://www.h-schmidt.net/FloatConverter/IEEE754.html
	https://chummersone.github.io/qformat.html
	https://bitwisecmd.com/#255
	YT:
	https://www.youtube.com/watch?v=H-jbVrd9wvM
	https://www.youtube.com/watch?v=BN1g6puBuRM

	Fixed points:
	https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html
*/
int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << std::roundf(42.42 * 256);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

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