/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/08/04 13:34:31 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Swap.hpp"
#include "min_max.hpp"
#include <iostream>
#include "text_colors.hpp"

struct ThreeBitField {
    uint8_t x : 3;
    uint8_t y : 3;
};

// int main()
// {
// 	{
// 		int x = 4, y = 20;
// 		std::cout << WHITE << "SWAP()" << std::endl;
// 		std::cout << DARKGREY;
// 		std::cout << "x " << x << ",y " << y << std::endl;
// 		Swap(&x, &y);
// 		std::cout << "x " << x << ",y " << y << std::endl;
// 		std::cout << RESET;
// 	}
// 	{
// 		double x = 4.123, y = 20;
// 		std::cout << GREEN;
// 		std::cout << "x " << x << ",y " << y << std::endl;
// 		Swap(&x, &y);
// 		std::cout << "x " << x << ",y " << y << std::endl;
// 		std::cout << RESET;
// 	}
// 	{
// 		std::string x = "helloo", y = "barbecue";
// 		std::cout << BLUE;
// 		std::cout << "x " << x << ",y " << y << std::endl;
// 		Swap(&x, &y);
// 		std::cout << "x " << x << ",y " << y << std::endl;
// 		std::cout << RESET;
// 	}
// 	{
// 		uint8_t x = 0b10001010, y = 0b10001010;
// 		std::cout << WHITE << "MIN()" << std::endl;

// 		std::cout << MAGENTA;
// 		std::cout << "x " << static_cast<int>(x) << ",y " << static_cast<int>(y) << std::endl;
		
// 		std::cout << "min = " << static_cast<int>(Min(x, y)) << std::endl;
// 		std::cout << RESET;
// 	}
// 	{
// 		ThreeBitField one = {0b011, 0b111};
// 		std::cout << WHITE << "MAX()" << std::endl;

// 		std::cout << RED;
// 		std::cout << "x " << static_cast<int>(one.x) << ",y " << static_cast<int>(one.y) << std::endl;
// 		std::cout << "max = " << static_cast<int>(Max(one.x, one.y)) << std::endl;
// 		std::cout << RESET;
// 	}
// }

int main()
{	
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}