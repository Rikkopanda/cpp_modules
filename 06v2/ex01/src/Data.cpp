/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/03 10:35:59 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "Data default constructor called" << std::endl;
	#endif
}

Data::Data(int data_input)
{
	this->some_data = data_input;
	#ifdef PRINT_MORE_INFO
	 std::cout << "Data parameter constructor called" << std::endl;
	#endif
}

Data::Data(Data &src) : some_data(src.getData())
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "Data copy constructor called" << std::endl;
	#endif
}

int Data::getData(void)
{
	return some_data;
}

Data::~Data(void)
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "Data destructor called" << std::endl;
	#endif
}

Data& Data::operator=(Data &src)
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "Data assignment operator called" << std::endl;
	#endif
	some_data = src.getData();
	return *this;
}
