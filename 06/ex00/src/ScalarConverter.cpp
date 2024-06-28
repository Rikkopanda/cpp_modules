/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/27 19:49:40 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdexcept>
#include <iomanip>
#include <math.h>
#include <ctype.h>
#include <string>
#include <float.h>
#include <limits.h>

bool ScalarConverter::impossible = false;
int ScalarConverter::char_flag = OKPRINT;
int ScalarConverter::int_flag = OKPRINT;
int ScalarConverter::float_flag = OK_FLOAT;
int ScalarConverter::double_flag = OKPRINT;
std::string ScalarConverter::saved_pseudo_literal;

// int count_digits(const char *str)
// {
// 	int i = 0;
// 	while (isdigit(str[i]))
// 	{
// 		i++;
// 	}
// 	return i;
// }

void possibilities(std::string &str)
{
	long double			dval;
	std::stringstream	ss1;

	ss1 << str;
	ss1 >> dval;
	std::cout << dval << " nice" << std::endl;
	if (float_inf_check(str))
	{
		ScalarConverter::float_flag = PSEUDO_LITERAL_F;
		ScalarConverter::char_flag = IMPOSSIBLE;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::double_flag = PSEUDO_LITERAL_D;
		return ;
	}
	else if (double_inf_check(str))
	{
		ScalarConverter::float_flag = PSEUDO_LITERAL_F;
		ScalarConverter::char_flag = IMPOSSIBLE;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::double_flag = PSEUDO_LITERAL_D;
		return ;
	}
	if (dval < 255)
	{
		if (isprint(dval))
			ScalarConverter::char_flag = OKPRINT;
		else
			ScalarConverter::char_flag = NON_DISPLAYABLE;
	}
	else
		ScalarConverter::char_flag = IMPOSSIBLE;
	if (!isdigit(str.c_str()[0]))
	{
		ScalarConverter::double_flag = IMPOSSIBLE;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::float_flag = IMPOSSIBLE;
		return ;
	}
	if (dval > __INT_MAX__ || dval < INT_MIN)
	{
		std::cout << "bigger than int " << dval << std::endl;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::char_flag = IMPOSSIBLE;
	}
	if ((dval > MAXFLOAT) || (-dval < -MAXFLOAT))
	{
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::char_flag = IMPOSSIBLE;
		ScalarConverter::float_flag = IMPOSSIBLE;
	}
	if (dval > DBL_MAX  || -dval < -DBL_MAX)
	{
		std::cout << "very big " << dval << std::endl;
		ScalarConverter::double_flag = IMPOSSIBLE;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::char_flag = IMPOSSIBLE;
		ScalarConverter::float_flag = IMPOSSIBLE;
	}
	std::cout << "stringstream " << dval << std::endl;
}
// 	if ((dval > DBL_MAX || (dval < DBL_MIN && dval >= 0)) || (-dval < -DBL_MAX || (-dval > -DBL_MIN && dval <= 0)))

int is_char_literal(std::string &str)
{
	if (str.length() == 1 && isprint(str.c_str()[0]))
	{
		ScalarConverter::char_flag = OKPRINT;
		return true;
	}
	return false;
}

void convert_from_char(std::string &str)
{
	const char val = str.c_str()[0];

	print_value(static_cast<char>(val), ScalarConverter::char_flag, "char");
	print_value(static_cast<int>(val), ScalarConverter::int_flag, "int");
	print_value(static_cast<float>(val), ScalarConverter::float_flag, "float");
	print_value(static_cast<double>(val), ScalarConverter::char_flag, "double");//still to print extra .0
}

// int is_int_literal(std::string &str)
// {
// 	size_t pos;

// 	try {
// 		std::stoi(str, &pos);
// 	} catch (std::exception &e)
// 	{
// 		ScalarConverter::char_flag = IMPOSSIBLE;
// 		ScalarConverter::float_flag = IMPOSSIBLE;
// 		ScalarConverter::double_flag = IMPOSSIBLE;
// 		ScalarConverter::int_flag = IMPOSSIBLE;
// 		std::cout << "is_int_literal() exception: " << e.what() << std::endl;
// 		return false;
// 	}
// 	return (pos == str.length());
// }

void convert_from_int(std::string &str)
{
	std::stringstream	ss;
	int					val;

	ss << str;
	ss >> val;	
	print_value(static_cast<int>(val), ScalarConverter::int_flag, "int");
	print_value(static_cast<char>(val), ScalarConverter::char_flag, "char");
	print_value(static_cast<float>(val), ScalarConverter::float_flag, "float");
	print_value(static_cast<double>(val), ScalarConverter::double_flag, "double");
}

int is_float_literal(std::string &str)
{
	if (float_inf_check(str))
	{
		// ScalarConverter::float_flag = OK_FLOAT;
		// ScalarConverter::char_flag = IMPOSSIBLE;
		// ScalarConverter::int_flag = IMPOSSIBLE;
		// ScalarConverter::double_flag = OKPRINT;
		// std::cout << "float_flag:" << ScalarConverter::float_flag << std::endl;
		return true;
	}
	return str.back() == 'f' && double_inf_check(str) == false;
}

void convert_from_float(std::string &str)
{
	std::stringstream	ss;
	float				val;

	ss << str;
	ss >> val;	
	// std::cout << "intflag:" << ScalarConverter::float_flag << std::endl;
	print_value(static_cast<float>(val), ScalarConverter::float_flag, "float");
	print_value(static_cast<double>(val), ScalarConverter::double_flag, "double");
	print_value(static_cast<int>(val), ScalarConverter::int_flag, "int");
	print_value(static_cast<char>(val), ScalarConverter::char_flag, "char");
}

int double_inf_check(std::string &str)
{
	if (str == "-inf" || str == "nan" || str == "+inf" || str == "inf")
	{
		ScalarConverter::saved_pseudo_literal = str;
		return true;
	}
	return false;
}

int float_inf_check(std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
	{
		ScalarConverter::saved_pseudo_literal = str;
		return true;
	}
	return false;
}

int is_double_literal(std::string &str)
{
	if (double_inf_check(str))
	{
		return true;
	}
	// std::cout << "found " << str.rfind('.') << std::endl;
	return (str.rfind('.') != std::string::npos && str.rfind('.') != 0) || (ScalarConverter::int_flag == IMPOSSIBLE && ScalarConverter::double_flag != IMPOSSIBLE) ;
}

void convert_to_pseudo_float(std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan" || str == "inf")
	{
		str = str + "f";
	}
}

void convert_to_pseudo_double(std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
	{
		str.pop_back();
		// std::cout << str << " hello" <<std::endl;
		// str.erase(str.back() - 1, 1);
	}
}
template <typename T>

void print_value(T val, int flag, std::string datatype)
{
	switch (flag)
	{
	case e_bitflags::OKPRINT:
		std::cout << datatype << ":\t"  << val << std::endl;
		break;
	case e_bitflags::NON_DISPLAYABLE:
		std::cout << datatype << ":\t"  << "Non displayable" << std::endl;
		break;
	case e_bitflags::IMPOSSIBLE:
		std::cout << datatype << ":\t"  << "impossible" << std::endl;
		break;
	case e_bitflags::OK_FLOAT:
		std::cout << datatype << ":\t"  << val << "f" << std::endl;
		break;
	case e_bitflags::PSEUDO_LITERAL_F:
		convert_to_pseudo_float(ScalarConverter::saved_pseudo_literal);
		std::cout << datatype << ":\t"  << ScalarConverter::saved_pseudo_literal << std::endl;
		break;
	case e_bitflags::PSEUDO_LITERAL_D:
		convert_to_pseudo_double(ScalarConverter::saved_pseudo_literal);
		std::cout << datatype << ":\t"  << ScalarConverter::saved_pseudo_literal << std::endl;
	}
}

void convert_from_double(std::string &str)
{
	std::stringstream	ss;
	double				val;

	ss << str;
	ss >> val;
	print_value(static_cast<double>(val), ScalarConverter::double_flag, "double");
	print_value(static_cast<float>(val), ScalarConverter::float_flag, "float");
	print_value(static_cast<int>(val), ScalarConverter::int_flag, "int");
	print_value(static_cast<char>(val), ScalarConverter::char_flag, "char");
}

void ScalarConverter::convert(std::string str_of_literal)
{
	// std::cout << "intflag:" << ScalarConverter::int_flag << std::endl;

	possibilities(str_of_literal);
	if (is_char_literal(str_of_literal))
		convert_from_char(str_of_literal);
	else if (is_float_literal(str_of_literal))
		convert_from_float(str_of_literal);
	else if (is_double_literal(str_of_literal))
		convert_from_double(str_of_literal);
	else if (ScalarConverter::int_flag == OKPRINT)
		convert_from_int(str_of_literal);
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