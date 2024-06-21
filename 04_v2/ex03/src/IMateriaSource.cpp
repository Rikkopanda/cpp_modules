/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:43:56 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/05/09 11:20:18 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	if (PRINT_ALL == TRUE)
		std::cout << "IMateriaSource Default constructor operator called" << RESET << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &src)
{
	if (PRINT_ALL == TRUE)
		std::cout << "IMateriaSource copy constructor operator called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
	*this = src;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource &src)
{
	if (PRINT_ALL == TRUE)
		std::cout << "IMateriaSource Assignation operator called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] != NULL)
			delete this->slots[i];
		this->slots[i] = src.slots[i];
	}
	return *this;
}

IMateriaSource::~IMateriaSource()
{
	if (PRINT_ALL == TRUE)
		std::cout << "IMateriaSource destructor called" << RESET << std::endl;
}

/**
 * allocation and freeing memory is as followed:
 * 
 * it is assumed for all AMateria's passed to learnMateria(AMateria* m),
 * that materiaSource object is responsible for the
 * destructing and freeing memory of those
 * 
 * be careful!;
 * 
 * to not cause invalid freeing, do not equip a Character with a AMateria
 * who is also learned by MateriaSource
 * 
*/
void IMateriaSource::learnMateria(AMateria* m)
{
	(void)m;
	if (PRINT_ALL == TRUE)
		std::cout << "learnMateria called: does nothing, this is a abstract base class" << RESET << std::endl;
}

AMateria* IMateriaSource::createMateria(std::string const & type)
{
	(void)type;
	if (PRINT_ALL == TRUE)
		std::cout << "createMateria called: does nothing, this is a abstract base class" << RESET << std::endl;
	return (NULL);
}
