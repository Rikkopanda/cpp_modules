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
	std::cout << "ClapTrap default constructor called" << std::endl;
	attack_damage = CLAP_ATTACK_DAMAGE;
	hit_points = CLAP_HIT_PTS;
	energy_points = CLAP_ENERGY_PTS;
}

ClapTrap::ClapTrap(std::string	name)
{
	std::cout << "ClapTrap " << name << " parameter constructor called" << std::endl;
	this->name = name;
	attack_damage = CLAP_ATTACK_DAMAGE;
	hit_points = CLAP_HIT_PTS;
	energy_points = CLAP_ENERGY_PTS;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor operator called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->attack_damage = src.attack_damage;
	this->energy_points = src.energy_points;
	this->hit_points = src.hit_points;
	this->name = src.name;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target
			<< ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else if (energy_points == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points left to attack" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " has no hit points left to attack" << std::endl;

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points > amount)
	{
		hit_points -= amount;
	}
	else if (hit_points > 0)
		hit_points = 0;
	else
	{
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " took " << amount << " amount of damage, he now has "
		<< hit_points << " hit points left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		hit_points += amount;
		std::cout << "ClapTrap " << name << " repaired itself and gained " << amount
			<< " of hit points, he now has " << hit_points << "hit points." << std::endl;
		energy_points--;
	}
	else if (energy_points == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points left to repair" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " has no hit points left to repair" << std::endl;
}
