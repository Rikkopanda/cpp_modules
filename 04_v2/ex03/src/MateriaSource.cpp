/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:23:52 by rverhoev          #+#    #+#             */
/*   Updated: 2024/05/09 11:19:26 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:43:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/05/07 11:20:00 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
	if (PRINT_ALL == TRUE)
		std::cout << "MateriaSource Default constructor operator called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src): IMateriaSource()
{
	if (PRINT_ALL == TRUE)
		std::cout << "MateriaSource copy constructor operator called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
	*this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
	if (PRINT_ALL == TRUE)
		std::cout << "MateriaSource Assignation operator called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] != NULL)
			delete this->slots[i];
		this->slots[i] = src.slots[i];
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	if (PRINT_ALL == TRUE)
		std::cout << "MateriaSource destructor called" << RESET << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] != NULL)
		{
			if (PRINT_ALL == TRUE) std::cout << Purple << "deleting Materia at slot " << i << RESET << std::endl;
			delete this->slots[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	int	i;

	if (PRINT_ALL == TRUE)
		std::cout << "learnMateria called" << RESET << std::endl;
	i = 0;
	while (this->slots[i] != NULL)
	{
		i++;
		if (i == 3)
		{
			if (PRINT_ALL == TRUE)
				std::cout << Purple << "learnMateria: last one replaced" << RESET << std::endl;
			delete this->slots[i];
			break ;
		}
	}
	this->slots[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria*	newMateria;
	int			i;

	if (PRINT_ALL == TRUE)
		std::cout << "createMateria called" << RESET << std::endl;
	newMateria = NULL;
	i = 3;
	while (i >= 0)
	{
		if (this->slots[i] == NULL)
		{
			i--;
			continue;
		}
		if (this->slots[i]->getType() == type)
		{
			newMateria = this->slots[i]->clone();
			return (newMateria);
		}
		i--;
	}
	if (PRINT_ALL == TRUE)
		std::cout << "MateriaSource slots are full" << RESET << std::endl;
	return (NULL);
}
