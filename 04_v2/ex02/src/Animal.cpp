/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:56:57 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

_Animal::_Animal()
{
	std::cout << "_Animal default constructor called" << RESET << std::endl;
	type = "Default _Animal";
}

_Animal::_Animal(_Animal &src)
{
	std::cout << "_Animal copy constructor operator called" << RESET << std::endl;
	*this = src;
}

_Animal &_Animal::operator=(const _Animal &src)
{
	(void)src;
	std::cout << "_Animal Assignation operator called: does nothing" << RESET << std::endl;
	return *this;
}

_Animal::~_Animal()
{
	std::cout << "_Animal " << type << " destructor called" << RESET << std::endl;
}

std::string _Animal::getType() const{return this->type;}
