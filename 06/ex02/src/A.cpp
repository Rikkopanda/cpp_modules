/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/02 17:49:05 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

std::string A::TypeName()
{
	return "A";
}

A::A()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "A's constructor called" << std::endl;
	#endif
}

A::~A()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "A's destructor called" << std::endl;
	#endif
}