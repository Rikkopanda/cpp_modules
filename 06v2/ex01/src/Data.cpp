/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/02 20:04:57 by rverhoev         ###   ########.fr       */
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
	this->some_data = data_input;
	if (PRINT_ALL) std::cout << "Data parameter constructor called" << std::endl;
}

Data::Data(Data &src) : some_data(src.getData())
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
