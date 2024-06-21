/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:56:57 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << Blue;
	std::cout << "ClapTrap \tdefault constructor called" << std::endl;
	std::cout << Default_restore;
	attack_damage = 0;
	hit_points = 10;
	energy_points = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << Blue;
	std::cout << "ClapTrap\t" << White << name << Blue << " parameter constructor called" << std::endl;
	std::cout << Default_restore;
	this->name = name;
	attack_damage = 0;
	hit_points = 10;
	energy_points = 10;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << Blue;
	std::cout << "ClapTrap \tcopy constructor operator called" << std::endl;
	std::cout << Default_restore;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << Blue;
	std::cout << "ClapTrap \tAssignation operator called" << std::endl;	std::cout << Default_restore;
	this->attack_damage = src.attack_damage;
	this->energy_points = src.energy_points;
	this->hit_points = src.hit_points;
	this->name = src.name;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << Blue;
	std::cout << "ClapTrap \t" << White << ClapTrap::name << Blue << " destructor called" << std::endl;
	std::cout << Default_restore;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << Blue;
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap \t" << White << ClapTrap::name << Blue << " attacks " << target
			<< ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else if (energy_points == 0)
		std::cout << "ClapTrap \t" << White << ClapTrap::name << Blue << " has no energy points left to attack" << std::endl;
	else
		std::cout << "ClapTrap \t" << White << ClapTrap::name << Blue << " has no hit points left to attack" << std::endl;
	std::cout << Default_restore;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << Blue;
	if (hit_points > amount)
	{
		hit_points -= amount;
	}
	else if (hit_points > 0)
		hit_points = 0;
	else
	{
		std::cout << "ClapTrap \t" << White << name << Blue << " is already dead" << std::endl;
		std::cout << Default_restore;
		return ;
	}
	std::cout << "ClapTrap \t" << White << name << Blue << " took " << amount << " amount of damage, he now has "
		<< hit_points << " hit points left" << std::endl;
	std::cout << Default_restore;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		hit_points += amount;
		std::cout << "ClapTrap \t" << White << name << Blue << " repaired itself and gained " << amount
			<< " of hit points, he now has " << hit_points << "hit points." << std::endl;
		energy_points--;
	}
	else if (energy_points == 0)
		std::cout << this->name << " has no energy points left to repair" << std::endl;
	else
		std::cout << this->name << " has no hit points left to repair" << std::endl;
	std::cout << Default_restore;
}
