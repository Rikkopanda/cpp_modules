/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/28 09:59:59 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

std::string A::TypeName()
{
	return "A";
}

A::A()
{
	std::cout << "A's constructor called" << std::endl;
}

A::~A()
{
	std::cout << "A's destructor called" << std::endl;
}