/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/25 21:08:01 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdexcept>
#include <iomanip>
#include <math.h>

bool ScalarConverter::impossible = false;

void print_scalar(int scalar, const char *cstr)
{
	if (ScalarConverter::impossible)
	{
		std::cout << "int:\timpossible" << std::endl;
		return ;
	}
	std::cout << "int:\t" << scalar << std::endl;
}

void print_scalar(char scalar, const char *cstr)
{
	if (ScalarConverter::impossible || std::isprint(scalar) == false)
	{
		std::cout << "char:\t" << "impossible" << std::endl;
		return ;
	}
	std::cout << "char:\t"  << scalar << std::endl;
}

template <typename T>
/*
	what are default values:
	https://stackoverflow.com/questions/51968579/what-are-the-default-format-flags-and-widths-for-double-output-in-a-stdstrin
*/
void floating_point_print(T scalar, std::string print_type)
{
	if (std::floor(scalar) == scalar)
	{
		std::fixed(std::cout);
		std::cout.precision(1);
		std::cout << print_type << ":\t" << scalar << std::flush;
		std::defaultfloat(std::cout);
		std::cout << std::setprecision(6);
		return ;
	}
	std::cout << print_type << ":\t" << scalar << std::flush;
}

void print_scalar(float scalar, const char *cstr)
{
	if (ScalarConverter::impossible)
	{
		std::cout << "float:\t" << std::setw(7) << "impossible" << std::endl;
		return ;
	}
	floating_point_print(scalar, "float");
	std::cout << "f" << std::endl;
}

// std::cout << "________\nFIRST float: " << scalar << "f" << std::endl;
// std::cout.unsetf(std::ios::floatfield);
// std::cout << std::setprecision(8);
// std::cout << "precision: " << std::cout.precision() << std::endl;
// std::cout << "float: " << scalar << "f" << std::endl;
// std::fixed(std::cout);
// std::cout << std::setprecision(8);
// std::cout << "precision: " << std::cout.precision() << std::endl;
// std::cout << "float: " << scalar << "f" << std::endl;
// std::cout.unsetf(std::ios::floatfield);
// std::resetiosflags(std::ios::floatfield); // sets the format flag to reset value
// std::showbase(std::cout);// same as above manipulator, this gives 0x or 0 prefixes depending on set base
// std::noshowbase(std::cout); //unsets

void print_scalar(double scalar, const char *cstr)
{
	if (ScalarConverter::impossible)
	{
		std::cout << "double:\timpossible" << std::endl;
		return ;
	}
	floating_point_print(scalar, "double");
	std::cout << std::endl;
}

void init_statics()
{
	ScalarConverter::impossible = false;
}

void check_impossible_nonnum(const char *cstr)
{
	if (cstr[0] != '0' && std::atoi(cstr) == 0)
		ScalarConverter::impossible = true;
	else
		ScalarConverter::impossible = false;
}

void ScalarConverter::convert(std::string str_of_literal)
{
	init_statics();

	const char *cstr = str_of_literal.c_str();
	float _float = std::atof(cstr);
	double _double = std::atof(cstr);
	int integer = std::atoi(cstr);
	char character = integer;

	char ac



	check_impossible_nonnum(cstr);
	print_scalar(integer, cstr);
	print_scalar(_float, cstr);
	print_scalar(_double, cstr);
	print_scalar(static_cast<char>(integer), cstr);
}
// str->actual type -> convert to three other data types
// display
// atoi();
// alnum();
// alchar();
// float check
// double check  xxxxx.xxxxxf