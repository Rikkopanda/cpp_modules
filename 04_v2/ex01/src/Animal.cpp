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
	this->brain = new Brain();
}

_Animal::_Animal(std::string	type)
{
	std::cout << "_Animal " << type << " parameter constructor called" << RESET << std::endl;
	this->type = type;
	this->brain = new Brain();
}

_Animal::_Animal(_Animal &src)
{
	std::cout << "_Animal copy constructor operator called" << RESET << std::endl;
	this->brain = NULL;
	*this = src;
}

/**
 * incoming could be:
 * shared pointer of object pointers inside class.
 * or duplicate.
 * 
 * for this duplicate is suitable, its a copy
*/
_Animal &_Animal::operator=(const _Animal &src)
{
	std::cout << "_Animal Assignation operator called" << RESET << std::endl;
	Brain *tmp = new Brain(*src.brain);

	this->type = src.type;
	if (this->brain != NULL)
		delete this->brain;
	this->brain = tmp;
	return *this;
}

_Animal::~_Animal()
{
	std::cout << "_Animal " << type << " destructor called" << RESET << std::endl;
	delete this->brain;
}

void	_Animal::makeSound() const{std::cout << "beep beep\n" << RESET << std::endl;}

std::string _Animal::getType() const{return this->type;}

void _Animal::BrainScan()
{
	std::cout << "_Animal BrainScan:" << RESET << std::endl;

	for (int i = 0; i < 100; i++)
	{
		if (this->brain->ideas[i].length() == 0)
			continue;
		std::cout << this->brain->ideas[i] << RESET << std::endl;
	}
	std::cout << "Done" << RESET << std::endl;
}

void _Animal::setBrain()
{
	std::string	user_input;

	std::cout << "_Animal Brain: Hit q if you want to exit " << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Input string at position " << i << ":" << RESET << std::endl;
		std::cin >> user_input;
		if (user_input.compare("q") == 0)
			break;
		this->brain->ideas[i] = user_input;
		std::cout << "Registered: " << user_input << RESET << std::endl;
	}
	std::cout << "Done" << RESET << std::endl;
}

Brain *_Animal::getBrain()
{
	return this->brain;
}

void _Animal::BrainCopy(Brain *src)
{
	std::cout << "Animal " << this->getType() << ": Brain Copy function called" << RESET << std::endl;
	if (this->brain != src)
	{
		for (int i = 0; i < 100; i++)
		{
			this->brain->ideas[i] = src->ideas[i];
			// if (src->ideas[i].length() == 0)
			// 	continue ;
			// std::cout << "Copied: " << this->brain->ideas[i] << RESET << std::endl;
		}
	}
	else
		std::cout << "Don't have to copy on to itself" << RESET << std::endl;
}

void _Animal::moveBrain(_Animal *target)
{
	std::cout << "_Animal Brain moving from  " << this->getType() << " towards " << target->getType() << RESET << std::endl;
	target->BrainCopy(this->getBrain());
	this->brain->BrainErasor();
}
