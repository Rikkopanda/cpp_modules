/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/07/03 10:24:39 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>

enum e_bitflags
{
	OKPRINT,
	IMPOSSIBLE,
	OK_FLOAT,
	NON_DISPLAYABLE,
	PSEUDO_LITERAL_F,
	DOUBLE_ADD_DOT_ZERO,
	PSEUDO_LITERAL_D
};

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(const std::string useless_str);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(ScalarConverter &src);
		static bool impossible;
		static int double_flag;
		static int char_flag;
		static int int_flag;
		static int float_flag;
		static int total_flag_bitmask;
		static std::string saved_pseudo_literal;
		static void convert(std::string str_of_literal);
		virtual ~ScalarConverter(void) = 0;
};

template <typename T>

void print_value(T val, int flag, std::string datatype);
int double_inf_check(std::string &str);
int float_inf_check(std::string &str);

#endif