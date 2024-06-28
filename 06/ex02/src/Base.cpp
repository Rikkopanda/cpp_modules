/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CreBaseted: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   UpdBaseted: 2024/06/28 09:14:02 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

std::string Base::TypeName()
{
	return "Base";
}

Base::Base()
{
	std::cout << "Base constructor called" << std::endl;
}

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}