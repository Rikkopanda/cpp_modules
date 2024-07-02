/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/02 19:05:49 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include "text_colors.hpp"

std::string B::TypeName()
{
	return "B";
}

B::B()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "B constructor called" << RESET << std::endl;
	#endif
}

B::~B()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "B destructor called" << RESET << std::endl;
	#endif
}