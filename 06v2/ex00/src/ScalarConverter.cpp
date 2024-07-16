/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/07/16 09:30:40 by rikverhoeve      ###   ########.fr       */
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
#include <sstream>

bool ScalarConverter::impossible = false;
int ScalarConverter::char_flag = OKPRINT;
int ScalarConverter::int_flag = OKPRINT;
int ScalarConverter::float_flag = OK_FLOAT;
int ScalarConverter::double_flag = OKPRINT;
std::string ScalarConverter::saved_pseudo_literal;
static std::string extra_for_double("");
static std::string extra_for_float("f");


ScalarConverter::ScalarConverter()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "ScalarConverter's constructor called" << RESET << std::endl;
	#endif
}

ScalarConverter::~ScalarConverter()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "ScalarConverter's destructor called" << RESET << std::endl;
	#endif
}

ScalarConverter::ScalarConverter(const std::string useless_str)
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "ScalarConverter's parameter constructor called with: " << useless_str << RESET << std::endl;
	#endif
	#ifndef PRINT_MORE_INFO
	 (void)useless_str;
	#endif
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "ScalarConverter's copy constructor called" << RESET << std::endl;
	#endif
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter &src)
{
	(void)src;
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "ScalarConverter assignment operator called" << RESET << std::endl;
	#endif
	return *this;
}

void possibilities(std::string &str, std::stringstream	&ss)
{
	long double		dval;
	char			cval = 0;

	ss << str;
	if (ss.str().size() == 1)
	{
		ss >> cval;
		dval = static_cast<double>(cval);
	}
	else
	{
		ss >> dval;
	}
	// std::cout << "now cval: " << cval << std::endl;
	// std::cout << "now " << dval << std::endl;
	// std::cout << "str " << str << std::endl;
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
	// std::cout << "now " << dval << std::endl;
	if (static_cast<int>(dval) < 255 && static_cast<int>(dval) >= 0)
	{
		// std::cout << "yes: " << static_cast<int>(dval) << std::endl;
		if (isprint(static_cast<int>(dval)))
			ScalarConverter::char_flag = OKPRINT;
		else
			ScalarConverter::char_flag = NON_DISPLAYABLE;
	}
	else
		ScalarConverter::char_flag = IMPOSSIBLE;
	// std::cout << "now2 " << dval << std::endl;

	if (!isdigit(str.c_str()[0]) && dval == 0)
	{
		// std::cout << "1 " << dval << std::endl;
		ScalarConverter::double_flag = IMPOSSIBLE;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::float_flag = IMPOSSIBLE;
		return ;
	}
	if (dval > __INT_MAX__ || dval < INT_MIN)
	{
		// std::cout << "2 " << dval << std::endl;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::char_flag = IMPOSSIBLE;
	}
	if ((dval > MAXFLOAT) || (-dval < -MAXFLOAT))
	{
		// std::cout << "bigger than int " << dval << std::endl;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::char_flag = IMPOSSIBLE;
		ScalarConverter::float_flag = IMPOSSIBLE;
	}
	if (dval > DBL_MAX  || -dval < -DBL_MAX)
	{
		// std::cout << "very big " << dval << std::endl;
		ScalarConverter::double_flag = IMPOSSIBLE;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::char_flag = IMPOSSIBLE;
		ScalarConverter::float_flag = IMPOSSIBLE;
	}
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

	extra_for_double = "";
	print_value(static_cast<char>(val), ScalarConverter::char_flag, "char");
	print_value(static_cast<int>(val), ScalarConverter::int_flag, "int");
	extra_for_float = ".0f";
	extra_for_double = ".0";
	print_value(static_cast<float>(val), ScalarConverter::float_flag, "float");
	print_value(static_cast<double>(val), ScalarConverter::char_flag, "double");
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


	extra_for_double = "";
	print_value(static_cast<int>(val), ScalarConverter::int_flag, "int");
	print_value(static_cast<char>(val), ScalarConverter::char_flag, "char");
	
	extra_for_float = ".0f";
	extra_for_double = ".0";
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

void convert_from_float(std::string &str, int digits_after_dot)
{
	std::stringstream	ss;
	float				val;

	ss << str;
	ss >> val;

	extra_for_float = "f";
	extra_for_double = "";

	if (str.rfind(".") == std::string::npos)
	{
		extra_for_float = ".0f";
		extra_for_double = ".0";
	}
	// isalnum(str.c_str()[str.rfind(".") - 1])
	std::cout << std::fixed;
	std::cout.precision(FLT_DIG < digits_after_dot ? FLT_DIG : digits_after_dot);
	print_value(static_cast<float>(val), ScalarConverter::float_flag, "float");
	std::cout.precision(DBL_DIG < digits_after_dot ? DBL_DIG : digits_after_dot);
	print_value(static_cast<double>(val), ScalarConverter::double_flag, "double");
	extra_for_double = "";
	print_value(static_cast<int>(val), ScalarConverter::int_flag, "int");
	print_value(static_cast<char>(val), ScalarConverter::char_flag, "char");
}
// std::cout << "intflag:" << ScalarConverter::float_flag << std::endl;

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

int because_very_big()
{
	if (ScalarConverter::int_flag == IMPOSSIBLE && ScalarConverter::double_flag != IMPOSSIBLE)
		return true;
	return false;
}

int because_double_format(std::string &str)
{
	if (str.rfind('.') != std::string::npos && str.rfind('.') != 0)
		return true;
	return false;
}

int is_double_literal(std::string str)
{
	if (double_inf_check(str))
	{
		return true;
	}
	// std::cout << "found " << str.rfind('.') << std::endl;
	return (because_double_format(str) || because_very_big());
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

#include <string>
#include "text_colors.hpp"

template <typename T>

void print_value(T val, int flag, std::string datatype)
{
	switch (flag)
	{
	case e_bitflags::OKPRINT:
		// std::cout << val << " hello" <<std::endl;
		std::cout << BLUE << datatype << ":\t"  << val << extra_for_double << RESET << std::endl;
		break;
	case e_bitflags::NON_DISPLAYABLE:
		std::cout << BLUE << datatype << ":\t"  << "Non displayable" << RESET << std::endl;
		break;
	case e_bitflags::IMPOSSIBLE:
		std::cout << BLUE << datatype << ":\t"  << "impossible" << RESET << std::endl;
		break;
	case e_bitflags::OK_FLOAT:
		std::cout << BLUE << datatype << ":\t"  << val << extra_for_float << RESET << std::endl;
		break;
	case e_bitflags::PSEUDO_LITERAL_F:
		convert_to_pseudo_float(ScalarConverter::saved_pseudo_literal);
		std::cout << BLUE << datatype << ":\t"  << ScalarConverter::saved_pseudo_literal << RESET << std::endl;
		break;
	case e_bitflags::PSEUDO_LITERAL_D:
		convert_to_pseudo_double(ScalarConverter::saved_pseudo_literal);
		std::cout << BLUE << datatype << ":\t"  << ScalarConverter::saved_pseudo_literal << RESET << std::endl;
	}
}

void convert_from_double(std::string &str, int digits_after_dot)
{
	std::stringstream	ss;
	double				val;

	ss << str;
	ss >> val;

	extra_for_float = "f";
	extra_for_double = "";
	std::cout << std::fixed;
	std::cout.precision(DBL_DIG < digits_after_dot ? DBL_DIG : digits_after_dot);
	print_value(static_cast<double>(val), ScalarConverter::double_flag, "double");
	std::cout.precision(FLT_DIG < digits_after_dot ? FLT_DIG : digits_after_dot);
	print_value(static_cast<float>(val), ScalarConverter::float_flag, "float");
	print_value(static_cast<int>(val), ScalarConverter::int_flag, "int");
	print_value(static_cast<char>(val), ScalarConverter::char_flag, "char");
}
// std::cout << std::fixed;
// if (ss.str().length() > 8)
// 	digits_after_dot = ss.str().length() - FLT_DIG;
// std::cout << std::setprecision(digits_after_dot > 0 ? digits_after_dot : 0);



std::string trim_to_number_str(const std::string &input, int *digits_after_dot)
{
	std::string result;
	bool		hasDot = false;

	for (int i = 0; i < static_cast<int>(input[i]); i++)
	{
		if (i == 0 && static_cast<int>(input[i]) == '-')
		{
			//ok
		}
		else if (hasDot == false && input[i] == '.')
			hasDot = true;
		else if (!std::isdigit(input[i]))
			break;
		if (hasDot == true && input[i] != '.')
			(*digits_after_dot)++;
		result += input[i];
	}
	return result;
}


void ScalarConverter::convert(std::string str_of_literal)
{
	std::stringstream	ss;
	int					digits_after_dot = 0;

	possibilities(str_of_literal, ss);
	trim_to_number_str(ss.str(), &digits_after_dot);
	if (is_char_literal(str_of_literal))
		convert_from_char(str_of_literal);
	else if (is_float_literal(str_of_literal))
		convert_from_float(str_of_literal, digits_after_dot);
	else if (is_double_literal(str_of_literal))
		convert_from_double(str_of_literal, digits_after_dot);
	else if (ScalarConverter::int_flag == OKPRINT)
		convert_from_int(str_of_literal);
	else
		std::cout << "no type correct type found" << std::endl;
}
// std::regex_replace(ss.str(), std::regex());
// std::cout << numbers_str << std::endl;
// str->actual type -> convert to three other data types
// display
// atoi();
// alnum();
// alchar();
// float check
// double check  xxxxx.xxxxxf