/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/27 22:11:12 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#define PRINT_ALL true

Data::Data(void)
{
	if (PRINT_ALL) std::cout << "Data default constructor called" << std::endl;
}

Data::Data(int data_input)
{
	if (PRINT_ALL) std::cout << "Data parameter constructor called" << std::endl;
}

Data::Data(Data &src)
{
	if (PRINT_ALL) std::cout << "Data copy constructor called" << std::endl;
}

int Data::getData(void)
{
	return some_data;
}

Data::~Data(void)
{
	if (PRINT_ALL) std::cout << "Data destructor called" << std::endl;
}

Data& Data::operator=(Data &src)
{
	if (PRINT_ALL) std::cout << "Data assignment operator called" << std::endl;
	some_data = src.getData();
	return *this;
}
