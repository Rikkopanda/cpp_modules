/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:43:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/05/09 11:17:30 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Amateria.hpp"

AMateria::AMateria()
{
	if (PRINT_ALL == TRUE)
		std::cout << "AMateria default constructor called" << RESET << std::endl;
	this->type = "Default AMateria";
}

AMateria::AMateria(std::string	const &type)
{
	if (PRINT_ALL == TRUE)
		std::cout << "AMateria " << type << " parameter constructor called" << RESET << std::endl;
	this->type = type;
}

AMateria::AMateria(AMateria &src)
{
	if (PRINT_ALL == TRUE)
		std::cout << "AMateria copy constructor operator called" << RESET << std::endl;
	*this = src;
}

/**
 * incoming could be:
 * shared pointer of object pointers inside class.
 * or duplicate.
 * 
 * for this duplicate is suitable, its a copy
*/
AMateria &AMateria::operator=(const AMateria &src)
{
	if (PRINT_ALL == TRUE)
		std::cout << "AMateria Assignation operator called" << RESET << std::endl;
	this->type = src.type;
	return *this;
}

AMateria::~AMateria()
{
	if (PRINT_ALL == TRUE)
		std::cout << "AMateria " << this->type << " destructor called" << RESET << std::endl;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	if (PRINT_ALL == TRUE)
		std::cout << "* Amateria base use function *" << std::endl;
}

AMateria* AMateria::clone() const
{
	return (AMateria*)this;
}

std::string const & AMateria::getType() const
{
	return this->type;
}
