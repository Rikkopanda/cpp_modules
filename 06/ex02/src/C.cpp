/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/02 17:49:23 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

std::string C::TypeName()
{
	return "C";
}

C::C()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "C constructor called" << std::endl;
	#endif
}

C::~C()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "C destructor called" << std::endl;
	#endif
}
