/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:43:42 by rverhoev          #+#    #+#             */
/*   Updated: 2024/05/08 16:00:13 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Cat::Cat()
{
	std::cout << Purple << "Cat default constructor called" << RESET << std::endl; 
	type = "Default Cat";
	this->brain = new Brain();
}

Cat::Cat(std::string type)
{
	std::cout << Purple << "Cat " << type << " parameter constructor called" << RESET << std::endl;
	this->type = type;
	this->brain = new Brain();
}

Cat::Cat(Cat &src):_Animal()
{
	std::cout << Purple << "Cat " << src.type << "(src) copy constructor operator called" << RESET << std::endl;
	this->brain = NULL;
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << Purple << "Cat " << src.type << "(src) Assignation operator called" << RESET << std::endl;
	Brain *tmp = new Brain(*src.brain);

	this->type = src.type;
	if (this->brain != NULL)
		delete this->brain;
	this->brain = tmp;
	return *this;
}

Cat::~Cat()
{
	std::cout << Purple << "Cat " << type << " destructor called" << RESET << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const{std::cout << Purple << type << ": meaaaouw\n" << RESET << std::endl;}

void Cat::setBrain()
{
	std::string	user_input;

	std::cout << Purple << "Cat Brain" << type << "(this): Hit q if you want to exit " << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << Purple << "Input string at position " << i << ":" << RESET << std::endl;
		std::cin >> user_input;
		if (user_input.compare("q") == 0)
			break;
		this->brain->ideas[i] = user_input;
		std::cout << Purple << "Registered: " << this->brain->ideas[i] << RESET << std::endl;
	}
	std::cout << Purple << "Done" << RESET << std::endl;
}

Brain *Cat::getBrain()
{
	return this->brain;
}

void Cat::BrainScan()
{
	std::cout << Purple << "Cat " << type << "(this) BrainScan:" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (this->brain->ideas[i].length() == 0)
			continue;
		std::cout << Purple << this->brain->ideas[i] << RESET << std::endl;
	}	
}

void Cat::BrainCopy(Brain *src)
{
	std::cout << Purple << "Brain Copy " << type << "(this) function called" << RESET << std::endl;
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
		std::cout << Purple << "Don't have to copy on to itself" << RESET << std::endl;
}

void Cat::moveBrain(Cat *target)
{
	std::cout << "Cat Brain moving from  " << this->getType() << " towards " << target->getType() << RESET << std::endl;
	target->BrainCopy(this->getBrain());
	this->brain->BrainErasor();
}
