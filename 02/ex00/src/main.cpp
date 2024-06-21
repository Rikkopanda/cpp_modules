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
#include "Fixed.hpp"
#include <limits>

/*
	coole calculator: https://www.h-schmidt.net/FloatConverter/IEEE754.html
	https://www.youtube.com/watch?v=H-jbVrd9wvM
	https://www.youtube.com/watch?v=BN1g6puBuRM

	Fixed points:
	https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html
*/
int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	// c.setRawBits(213);
	// std::cout << c.getRawBits() << std::endl;

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