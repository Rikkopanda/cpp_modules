/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/07/02 10:02:36 by rikverhoeve      ###   ########.fr       */
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

void possibilities(std::string &str, std::stringstream	*ss)
{
	long double			dval;

	*ss << str;
	*ss >> dval;
	std::cout << "now " << dval << std::endl;

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
	std::cout << "now " << dval << std::endl;
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
	std::cout << "now2 " << dval << std::endl;

	if (!isdigit(str.c_str()[0]) && dval == 0)
	{
		std::cout << "1 " << dval << std::endl;
		ScalarConverter::double_flag = IMPOSSIBLE;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::float_flag = IMPOSSIBLE;
		return ;
	}
	if (dval > __INT_MAX__ || dval < INT_MIN)
	{
		std::cout << "2 " << dval << std::endl;
		ScalarConverter::int_flag = IMPOSSIBLE;
		ScalarConverter::char_flag = IMPOSSIBLE;
	}
	if ((dval > MAXFLOAT) || (-dval < -MAXFLOAT))
	{
		std::cout << "bigger than int " << dval << std::endl;
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

void convert_from_float(std::string &str, int digits_after_dot)
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

int because_very_big(std::string &str)
{
	if (str.rfind('.') != std::string::npos && str.rfind('.') != 0)
		return true;
	return false;
}

int because_double_format(std::string &str)
{
	if (ScalarConverter::int_flag == IMPOSSIBLE && ScalarConverter::double_flag != IMPOSSIBLE)
		return true;
	return false;
}

int is_double_literal(std::string &str)
{
	if (double_inf_check(str))
	{
		return true;
	}
	// std::cout << "found " << str.rfind('.') << std::endl;
	return (because_double_format(str) || because_very_big(str));
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
	std::string dot_zero("");

	switch (flag)
	{
	case e_bitflags::OKPRINT:
		if (datatype == "double")
		{
			if (std::round(val) == val)
			{
				dot_zero = ".0";
			}
		}
		std::cout << datatype << ":\t"  << val << dot_zero << std::endl;
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

void convert_from_double(std::string &str, int digits_after_dot)
{
	std::stringstream	ss;
	double				val;

	ss << str;
	ss >> val;

	ss.str().length()
	// static_cast<int>(val)
	std::cout << std::fixed;
	std::cout << std::setprecision(DBL_DIG < digits_after_dot ? DBL_DIG : digits_after_dot);
	print_value(static_cast<double>(val), ScalarConverter::double_flag, "double");
	std::cout << std::fixed;
	std::cout << std::setprecision(FLT_DIG < digits_after_dot ? FLT_DIG : digits_after_dot);
	print_value(static_cast<float>(val), ScalarConverter::float_flag, "float");
	print_value(static_cast<int>(val), ScalarConverter::int_flag, "int");
	print_value(static_cast<char>(val), ScalarConverter::char_flag, "char");
}
#include <regex>


std::string trim_to_number_str(const std::string &input, int *digits_after_dot)
{
	std::string result;
	bool		hasDot = false;

	for (int i = 0; i < input.size(); i++)
	{
		if (i == 0 && input[i] == '-')
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
	// std::cout << "intflag:" << ScalarConverter::int_flag << std::endl;
	std::stringstream	ss;
	int					digits_after_dot = 0;

	possibilities(str_of_literal, &ss);
	std::cout << "stringstream " << ss.str() << std::endl;
	std::string numbers_str = trim_to_number_str(ss.str(), &digits_after_dot);
	// std::regex_replace(ss.str(), std::regex());
	std::cout << numbers_str << std::endl;




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
// str->actual type -> convert to three other data types
// display
// atoi();
// alnum();
// alchar();
// float check
// double check  xxxxx.xxxxxf