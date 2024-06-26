/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/26 08:55:31 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdexcept>
#include <iomanip>
#include <math.h>

bool ScalarConverter::impossible = false;
uint8_t ScalarConverter::char_flag = OKPRINT;
uint8_t ScalarConverter::int_flag = OKPRINT;
uint8_t ScalarConverter::float_flag = OK_FLOAT;
uint8_t ScalarConverter::double_flag = OKPRINT;


int is_char_literal(std::string &str)
{
	return (str.length() == 1 && isprint(str.c_str()[0]));
}

void convert_from_char(std::string &str)
{
	const char character = str.c_str()[0];

	std::cout << "char:\t"  << character << std::endl;
	std::cout << "int:\t"  << static_cast<int>(character) << std::endl;
	std::cout << "float:\t"  << static_cast<float>(character) << "f" << std::endl;
	std::cout << "double:\t"  << static_cast<double>(character) << std::endl;//still to print extra .0
}

int is_int_literal(std::string &str)
{
	size_t pos;

	try {
		std::stoi(str, &pos);
	} catch (std::exception &e)
	{
		ScalarConverter::char_flag = IMPOSSIBLE;
		ScalarConverter::float_flag = IMPOSSIBLE;
		ScalarConverter::double_flag = IMPOSSIBLE;
		ScalarConverter::int_flag = IMPOSSIBLE;
		std::cout << "is_int_literal() exception: " << e.what() << std::endl;
		return false;
	}
	return (pos == str.length());
}

void convert_from_int(std::string &str)
{
	const int val = std::stoi(str);

	std::cout << "int:\t"  << val << std::endl;
	std::cout << "char:\t"  << static_cast<char>(val) << std::endl;
	std::cout << "float:\t"  << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double:\t"  << static_cast<double>(val) << std::endl;//still to print extra .0
}

int is_float_literal(std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::char_flag = IMPOSSIBLE;
		return true;
	}
	return str.back() == 'f';
}

void convert_from_float(std::string &str)
{
	const float val = std::stof(str);
	
	std::cout << "float:\t"  << val << "f" << std::endl;
	std::cout << "int:\t"  << static_cast<int>(val) << std::endl;
	std::cout << "char:\t"  << static_cast<char>(val) << std::endl;
	std::cout << "double:\t"  << static_cast<double>(val) << std::endl;//still to print extra .0
}

int is_double_literal(std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		ScalarConverter::impossible = true;
		return true;
	}
	std::cout << "found " << str.rfind('.') << std::endl;
	return str.rfind('.') != std::string::npos && str.rfind('.') != 0;
}


enum e_bitflags
{
	OKPRINT = 1 << 0,
	IMPOSSIBLE = 1 << 1,
	OK_FLOAT = 1 << 2
};


template <typename T>


void print_value(T val, uint8_t flag, std::string datatype)
{
	switch (flag)
	{
	case e_bitflags::OKPRINT:
		std::cout << datatype << ":\t"  << val << std::endl;
		break;
	case e_bitflags::IMPOSSIBLE:
		std::cout << datatype << ":\t"  << "impossible" << std::endl;
		break;
	case e_bitflags::OK_FLOAT:
		std::cout << datatype << ":\t"  << val << "f" << std::endl;
	}

}

void convert_from_double(std::string &str)
{
	const double val = std::stod(str);

	std::cout << "double:\t"  << (val) << std::endl;//still to print extra .0false
	print_value(static_cast<float>(val), OK_FLOAT, "float");
	print_value(static_cast<int>(val), char_mask, "int");
	print_value(static_cast<char>(val), char_mask, "char");
}

void ScalarConverter::convert(std::string str_of_literal)
{
	if (is_char_literal(str_of_literal))
		convert_from_char(str_of_literal);
	else if (is_int_literal(str_of_literal))
		convert_from_int(str_of_literal);
	else if (is_float_literal(str_of_literal))
		convert_from_float(str_of_literal);
	else if (is_double_literal(str_of_literal))
		convert_from_double(str_of_literal);
	else
		std::cout << "no type correct type found" << std::endl;

}
// str->actual type -> convert to three other data types
// display
// atoi();
// alnum();
// alchar();
// float check
// double check  xxxxx.xxxxxf