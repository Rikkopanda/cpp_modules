/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/07/02 20:01:56 by rverhoev         ###   ########.fr       */
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
		static bool impossible;
		static int double_flag;
		static int char_flag;
		static int int_flag;
		static int float_flag;
		static int total_flag_bitmask;
		static std::string saved_pseudo_literal;

		// void print_scalar(char scalar, const char *cstr);
		// void print_scalar(float scalar, const char *cstr);
		// void print_scalar(double scalar, const char *cstr);
		// void print_scalar(int scalar, const char *cstr);
		// void check_impossible_nonnum(const char *cstr);
		static void convert(std::string str_of_literal);
		virtual ~ScalarConverter(void) = 0;
};

template <typename T>

void print_value(T val, int flag, std::string datatype);
int double_inf_check(std::string &str);
int float_inf_check(std::string &str);

#endif