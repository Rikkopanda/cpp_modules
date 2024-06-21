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

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(222 << 8);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	a.setRawBits((123 << 8) + 123);
	std::cout << a << std::endl;

	std::cout << "b / a " << b / a << std::endl;
	std::cout << "b * a " << b * a << std::endl;

	std::cout << "b * b * b * b * a " << b * b * b * b * a << std::endl;
	std::cout << "b / 0 " << b / 0 << std::endl;

	std::cout << "b + a " << b + a << std::endl;
	std::cout << "b - a " << b - a << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << Fixed::max( a, c ) << std::endl;
	std::cout << Fixed::min( a, c ) << std::endl;

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