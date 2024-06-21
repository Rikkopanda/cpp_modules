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

#include "Amateria.hpp"

Ice::Ice()
{
	this->type = "ice";
	if (PRINT_ALL == TRUE)
		std::cout << Blue << type << " default constructor called" << RESET << std::endl;
}

Ice::Ice(std::string	const &type)
{
	if (PRINT_ALL == TRUE)
		std::cout << Blue << type << " parameter constructor called" << RESET << std::endl;
	this->type = type;
}

Ice::Ice(Ice &src): AMateria()
{
	if (PRINT_ALL == TRUE)
		std::cout << Blue << src.type << " Ice copy constructor operator called" << RESET << std::endl;
	*this = src;
}

/**
 * incoming could be:
 * shared pointer of object pointers inside class.
 * or duplicate.
 * 
 * for this duplicate is suitable, its a copy
*/
Ice &Ice::operator=(const Ice &src)
{
	if (PRINT_ALL == TRUE)
		std::cout << Blue << src.type << " Assignation operator called" << RESET << std::endl;
	this->type = src.type;
	return *this;
}

Ice::~Ice()
{
	if (PRINT_ALL == TRUE)
		std::cout << Blue << type << " destructor called" << RESET << std::endl;
}

void Ice::use(ICharacter& target)
{
	std::cout << Blue << "* shoots an Ice bolt at " << target.getName() << " *"  << RESET << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria	*A;

	if (PRINT_ALL == TRUE)
		std::cout << Blue << type << " clone function called" << RESET << std::endl;
	A = new Ice(*(Ice*)this);
	return A;
}
