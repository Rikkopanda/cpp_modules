/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/28 09:59:35 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

std::string C::TypeName()
{
	return "C";
}

C::C()
{
	std::cout << "C constructor called" << std::endl;
}

C::~C()
{
	std::cout << "C destructor called" << std::endl;
}
