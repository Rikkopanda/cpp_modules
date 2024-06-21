/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:43:52 by rverhoev          #+#    #+#             */
/*   Updated: 2024/05/08 15:59:57 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog()
{
	std::cout << Blue << "Dog default constructor called" << RESET << std::endl;
	type = "Default Dog";
	this->brain = new Brain();
}

Dog::Dog(std::string type)
{
	std::cout << Blue << "Dog " << type << " parameter constructor called" << RESET << std::endl;
	this->type = type;
	this->brain = new Brain();
}

Dog::Dog(Dog &src):_Animal(src)
{
	std::cout << Blue << "Dog copy " << src.type << "(src) constructor operator called" << RESET << std::endl;
	this->brain = NULL;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << Blue << "Dog " << src.type << "(src) Assignation operator called" << RESET << std::endl;
	Brain *tmp = new Brain(*src.brain);

	this->type = src.type;
	if (this->brain != NULL)
		delete this->brain;
	this->brain = tmp;
	return *this;
}

Dog::~Dog()
{
	std::cout << Blue << "Dog " << type << " destructor called" << RESET << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const{std::cout << Blue << type << ": wOOOOOOFFFF\n" << RESET << std::endl;}

void Dog::setBrain()
{
	std::string	user_input;

	std::cout << Blue << "Dog Brain" << type << "(this): Hit q if you want to exit " << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << Blue << "Input string at position " << i << ":" << RESET << std::endl;
		std::cin >> user_input;
		if (user_input.compare("q") == 0)
			break;
		this->brain->ideas[i] = user_input;
		std::cout << Blue << "Registered: " << this->brain->ideas[i] << RESET << std::endl;
	}
	std::cout << Blue << "Done" << RESET << std::endl;
}

Brain *Dog::getBrain()
{
	return this->brain;
}

void Dog::BrainScan()
{
	std::cout << Blue << "Dog " << type << "(this) BrainScan:" << RESET << std::endl;

	for (int i = 0; i < 100; i++)
	{
		if (this->brain->ideas[i].length() == 0)
			continue;
		std::cout << Blue << this->brain->ideas[i] << RESET << std::endl;
	}	
}

void Dog::BrainCopy(Brain *src)
{
	std::cout << Blue << "Brain Copy " << type << "(this) function called" << RESET << std::endl;
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
		std::cout << Blue << "Don't have to copy on to itself" << RESET << std::endl;
}

void Dog::moveBrain(Dog *target)
{
	std::cout << "Dog Brain moving from  " << this->getType() << " towards " << target->getType() << RESET << std::endl;
	target->BrainCopy(this->getBrain());
	this->brain->BrainErasor();
}
