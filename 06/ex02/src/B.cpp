/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/02 17:48:47 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

std::string B::TypeName()
{
	return "B";
}

B::B()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "B constructor called" << std::endl;
	#endif
}

B::~B()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "B destructor called" << std::endl;
	#endif
}