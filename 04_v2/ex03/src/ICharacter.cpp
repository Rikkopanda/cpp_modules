/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:03:59 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/05/08 10:38:29 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Amateria.hpp"

ICharacter::ICharacter()
{
	this->name = "default name";
}

ICharacter::ICharacter(std::string _name)
{
	this->name = _name;
}

ICharacter::ICharacter(ICharacter &src)
{
	this->name = src.name;
}

ICharacter::~ICharacter()
{
	if (PRINT_ALL == TRUE)
		std::cout << "ICharacter destructor called" << RESET << std::endl;
}

std::string const & ICharacter::getName() const
{
	return this->name;
}

ICharacter& ICharacter::operator=(const ICharacter &src)
{
	this->name = src.name;
	return *this;
}

void ICharacter::equip(AMateria* m)
{
	int	i;

	i = 0;
	while (this->slots[i] != NULL)
	{
		i++;
	}
	this->slots[i] = m;
}

void ICharacter::unequip(int idx)
{
	this->slots[idx] = NULL;
}

void ICharacter::use(int idx, ICharacter& target)
{
	(void)target;
	(void)idx;
	// this->slots[idx].use(target);
}
