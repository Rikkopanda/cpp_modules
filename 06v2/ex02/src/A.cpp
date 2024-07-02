/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/02 19:05:46 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "text_colors.hpp"

std::string A::TypeName()
{
	return "A";
}

A::A()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "A's constructor called" << RESET << std::endl;
	#endif
}

A::~A()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "A's destructor called" << RESET << std::endl;
	#endif
}