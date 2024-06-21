/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:56:57 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**
 * name of claptrap is not initialized, this constructor is for when
 * using a diamond constructor, where Claptrap parameter constructor will be called also.
*/
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap\tdefault constructor called" << std::endl;
	guarding_bool = 0;
	attack_damage = SCAV_ATTACK_DAMAGE;
	hit_points = SCAV_HIT_PTS;
	energy_points = SCAV_ENERGY_PTS;
}

ScavTrap::ScavTrap(std::string	name)
{
	std::cout << "ScavTrap\t" << name << " parameter constructor called" << std::endl;
	this->name = name;
	guarding_bool = 0;
	attack_damage = SCAV_ATTACK_DAMAGE;
	hit_points = SCAV_HIT_PTS;
	energy_points = SCAV_ENERGY_PTS;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << "ScavTrap \tcopy constructor operator called" << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap \tAssignation operator called" << std::endl;
	attack_damage = src.attack_damage;
	this->ClapTrap::attack_damage = src.ClapTrap::attack_damage;
	this->ClapTrap::energy_points = src.ClapTrap::energy_points;
	this->ClapTrap::hit_points = src.ClapTrap::hit_points;
	this->ClapTrap::name = src.ClapTrap::name;
	this->energy_points = src.energy_points;
	this->hit_points = src.hit_points;
	this->name = src.name;
	this->guarding_bool = src.guarding_bool;
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << Blue;
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ScavTrap " << White << name << Blue << " attacks " << target
			<< ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else if (energy_points == 0)
		std::cout << "ScavTrap " << White << name << Blue << " has no energy points left to attack" << std::endl;
	else
		std::cout << "ScavTrap " << White << name << Blue << " has no hit points left to attack" << std::endl;
	std::cout << Default_restore;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap \t" << name << " destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (guarding_bool == true)
	{
		std::cout << "ScavTrap \t" << name << " is already in gate keeper mode" << std::endl;
		return ;
	}
	else
	{
		guarding_bool = true;
		std::cout << "ScavTrap \t" << name << " is now in gate keeper mode" << std::endl;
	}
}
