/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/28 09:59:45 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

std::string B::TypeName()
{
	return "B";
}

B::B()
{
	std::cout << "B constructor called" << std::endl;
}

B::~B()
{
	std::cout << "B destructor called" << std::endl;
}