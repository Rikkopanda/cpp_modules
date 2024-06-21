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

Cure::Cure()
{
	if (PRINT_ALL == TRUE)
		std::cout << Green << "Cure default constructor called" << RESET << std::endl;
	this->type = "cure";
}
Cure::Cure(std::string	const &type)
{
	if (PRINT_ALL == TRUE)
		std::cout << Green << "Cure " << type << " parameter constructor called" << RESET << std::endl;
	this->type = type;
}

Cure::Cure(Cure &copy): AMateria()
{
	if (PRINT_ALL == TRUE)
		std::cout << Green << "Cure copy constructor operator called" << RESET << std::endl;
	*this = copy;
}

/**
 * incoming could be:
 * shared pointer of object pointers inside class.
 * or duplicate.
 * 
 * for this duplicate is suitable, its a copy
*/
Cure &Cure::operator=(const Cure &src)
{
	if (PRINT_ALL == TRUE)
		std::cout << Green << "Cure Assignation operator called" << RESET << std::endl;
	this->type = src.type;
	return *this;
}

Cure::~Cure()
{
	if (PRINT_ALL == TRUE)
		std::cout << Green << "Cure " << type << " destructor called" << RESET << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << Green << "* heals " << target.getName() << "'s wounds *"
		 << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria	*A;

	if (PRINT_ALL == TRUE)
		std::cout << Green << type << " clone function called" << RESET << std::endl;
	A = new Cure(*(Cure*)this);
	return A;
}
