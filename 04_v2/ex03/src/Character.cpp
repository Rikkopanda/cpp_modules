
/** ***************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:14:34 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/05/08 10:26:04 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Amateria.hpp"

Character::Character()
{
	name = "default name";
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

Character::Character(std::string _name)
{
	this->name = _name;
	if (PRINT_ALL == TRUE)
		std::cout << Purple << "Character " << this->name << " parameter constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

Character::Character(Character &src): ICharacter()
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
	if (PRINT_ALL == TRUE)
		std::cout << Purple << "Character " << this->name << " copy constructor called" << RESET << std::endl;
	*this = src;
}

Character& Character::operator=(const Character &src)
{
	this->name = src.name;
	if (PRINT_ALL == TRUE)
		std::cout << Purple << "Character " << this->name << " operator overloader called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] != NULL)
			delete this->slots[i];
		this->slots[i] = src.slots[i];
	}
	return *this;
}

/**
 * assuming every Materia is made on the heap.
 * and not like this: 		
 * Chtr_ptr->equip(new Ice("other type"));
*/
Character::~Character()
{
	if (PRINT_ALL == TRUE)
		std::cout << Purple << "Character destructor called" << RESET << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] != NULL)
		{
			if (PRINT_ALL == TRUE)
				std::cout << Purple << "deleting Materia at slot " << i << RESET << std::endl;
			delete this->slots[i];
		}
	}
}

void Character::equip(AMateria* m)
{
	int	i;

	if (PRINT_ALL == TRUE)
		std::cout << Purple << "equip called" << RESET << std::endl;
	i = 0;
	while (this->slots[i] != NULL)
	{
		i++;
		if (i == 4)
		{
			if (PRINT_ALL == TRUE)
				std::cout << Purple << "equip: last one replaced" << RESET << std::endl;
			break ;
		}
	}
	this->slots[i] = m;
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
	{
		if (PRINT_ALL == TRUE)
			std::cout << Purple << "unequip: wrong id" << RESET << std::endl;
		return ;
	}	
	this->slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || idx < 0)
	{
		if (PRINT_ALL == TRUE)
			std::cout << Purple << "equip: wrong id" << RESET << std::endl;
		return ;
	}	
	if (this->slots[idx] == NULL)
	{
		if (PRINT_ALL == TRUE)
			std::cout << Purple << "use: no action in place" << RESET << std::endl;
		return ;
	}
	this->slots[idx]->use(target);
}
