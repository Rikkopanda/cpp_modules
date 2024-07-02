/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/02 19:05:51 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"
#include "text_colors.hpp"

std::string C::TypeName()
{
	return "C";
}

C::C()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "C constructor called" << RESET << std::endl;
	#endif
}

C::~C()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "C destructor called" << RESET << std::endl;
	#endif
}
