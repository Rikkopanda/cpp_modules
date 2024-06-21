/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:46:03 by rverhoev          #+#    #+#             */
/*   Updated: 2024/05/07 08:03:02 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Brain::Brain()
{
	std::cout << DARK_GRAY << "Brain default constructor called" << RESET << std::endl;
}

Brain::Brain(Brain &src)
{
	std::cout << DARK_GRAY << "Brain copy constructor operator called" << RESET << std::endl;
	*this = src; 
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << DARK_GRAY << "Brain Assignation operator called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << DARK_GRAY << "Brain " << " destructor called" << RESET << std::endl;
}
