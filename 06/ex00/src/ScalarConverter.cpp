/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/25 12:57:36 by rikverhoeve      ###   ########.fr       */
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
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << scalar << std::endl;
}

void print_scalar(char scalar, const char *cstr)
{
	if (ScalarConverter::impossible || std::isprint(scalar) == false)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	std::cout << "char: " << scalar << std::endl;
}

void print_scalar(float scalar, const char *cstr)
{
	if (ScalarConverter::impossible)
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	// std::cout << "precision: " << std::setprecision(8) << std::endl;
	
	std::cout << "________\nfloat: " << scalar << "f" << std::endl;

	// std::cout.unsetf(std::ios::floatfield);
	std::cout << std::setprecision(8);
	std::cout << "precision: " << std::cout.precision() << std::endl;
	std::cout << "float: " << scalar << "f" << std::endl;

	std::fixed(std::cout);
	std::cout << std::setprecision(8);

	std::cout << "precision: " << std::cout.precision() << std::endl;
	std::cout << "float: " << scalar << "f" << std::endl;
	// std::cout.unsetf(std::ios::floatfield);
	// std::resetiosflags(std::ios::showbase); // sets the format flag to reset value
	// std::showbase(std::cout);// same as above manipulator, this gives 0x or 0 prefixes depending on set base
	// std::noshowbase(std::cout); //unsets 
	std::cout.unsetf(std::ios::floatfield);

	std::cout << "float: " << scalar << "f" << std::endl;

	// if (std::floor(scalar) == scalar)
	// 	std::cout << std::fixed << std::setprecision(1);
}

void print_scalar(double scalar, const char *cstr)
{
	if (ScalarConverter::impossible)
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	// if (std::floor(scalar) == scalar)
	// 	std::cout << std::fixed << std::setprecision(6);
	std::cout << "double: " << scalar << std::endl;
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
	int integer = std::atoi(str_of_literal.c_str());
	char character = integer;

	print_scalar(integer, cstr);
	print_scalar(_float, cstr);
	print_scalar(_double, cstr);
	print_scalar(static_cast<char>(integer), cstr);

	// if (is_float(str_of_literal))
	// 	float fval = str_of_literal.toFloat();
	// std::cout << typeid(str_of_literal).name() << std::endl;
	// std::format("hi %f\n", _float);
}
// str->actual type -> convert to three other data types
// display

// atoi();
// alnum();
// alchar();
// float check
// double check  xxxxx.xxxxxf