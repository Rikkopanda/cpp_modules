/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                          :+:   :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:56:57 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "Default Frag name";
	high_five_request_bool = false;
	attack_damage = FRAG_ATTACK_DAMAGE;
	hit_points = FRAG_HIT_PTS;
	energy_points = FRAG_ENERGY_PTS;
}

FragTrap::FragTrap(std::string	name)
{
	std::cout << "FragTrap " << name << " parameter constructor called" << std::endl;
	this->name = name;
	high_five_request_bool = false;
	attack_damage = FRAG_ATTACK_DAMAGE;
	hit_points = FRAG_HIT_PTS;
	energy_points = FRAG_ENERGY_PTS;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap()
{
	std::cout << "FragTrap copy constructor operator called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	attack_damage = src.attack_damage;
	this->energy_points = src.energy_points;
	this->hit_points = src.hit_points;
	this->name = src.name;
	this->high_five_request_bool = src.high_five_request_bool;
	return *this;
}

void	FragTrap::attack(const std::string& target)
{
	std::cout << Blue;
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "FragTrap " << White << name << Blue << " attacks " << target
			<< ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else if (energy_points == 0)
		std::cout << "FragTrap "<< White << name << Blue << " has no energy points left to attack" << std::endl;
	else
		std::cout << "FragTrap "<< White << name << Blue << " has no hit points left to attack" << std::endl;
	std::cout << Default_restore;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (high_five_request_bool == false)
	{
		std::cout << "FragTrap \t"<< name << ": ayoo give me the five" << std::endl;
		high_five_request_bool = true;
		return ;
	}
	else
	{
		high_five_request_bool = false;
		std::cout << "FragTrap \t"<< name << ": hey man don't leave me hanging (still waiting to receive high five)" << std::endl;
	}
}
