/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/26 08:53:42 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>

typedef int *(* t_func_ptr)(std::string form_type_request_name, std::string target);

typedef struct s_func_table
{
	t_func_ptr	fptr;
	std::string matching_str;
} t_func_table;

class ScalarConverter {
	public:
		static bool impossible;
		static uint8_t double_flag;
		static uint8_t char_flag;
		static uint8_t int_flag;
		static uint8_t float_flag;

		// void print_scalar(char scalar, const char *cstr);
		// void print_scalar(float scalar, const char *cstr);
		// void print_scalar(double scalar, const char *cstr);
		// void print_scalar(int scalar, const char *cstr);
		// void check_impossible_nonnum(const char *cstr);
		static void convert(std::string str_of_literal);
};


#endif