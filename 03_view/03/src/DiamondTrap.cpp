/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:56:57 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
	default constructors called of scav, frag
	diamondtrap inherits from specified class, members and function 
*/
DiamondTrap::DiamondTrap(std::string _name): ClapTrap(_name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap\t" << _name << " parameter constructor called" << std::endl;
	this->name = _name;
	this->attack_damage = 30;
	this->hit_points = 100;
	this->energy_points = 50;
	std::cout << "attack " << this->attack_damage << "\thit points "
		<< this->hit_points << "\tenergy points " << this->energy_points << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "attack " << this->attack_damage << "\thit points " << this->hit_points << "\tenergy points " << this->energy_points << std::endl;

	std::cout << "DiamondTrap \tcopy constructor operator called" << std::endl;
	this->DiamondTrap::name = src.DiamondTrap::name;
	this->ClapTrap::attack_damage = src.ClapTrap::attack_damage;
	this->ClapTrap::energy_points = src.ClapTrap::energy_points;
	this->ClapTrap::hit_points = src.ClapTrap::hit_points;
	this->ScavTrap::guarding_bool = src.ScavTrap::guarding_bool;
	this->FragTrap::high_five_request_bool = src.FragTrap::high_five_request_bool;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src)
	{
		std::cout << "DiamondTrap \tAssignation operator called" << std::endl;
		this->ClapTrap::name = src.ClapTrap::name;
		this->ScavTrap::guarding_bool = src.ScavTrap::guarding_bool;
		this->FragTrap::high_five_request_bool = src.FragTrap::high_five_request_bool;
		this->name = src.name;
		this->attack_damage = FragTrap::attack_damage;
		this->hit_points = FragTrap::hit_points;
		this->energy_points = ScavTrap::energy_points;
		std::cout << "attack " << this->attack_damage << "\thit points " << this->hit_points << "\tenergy points " << this->energy_points << std::endl;
	}
	else
		std::cout << "DiamondTrap \tSelf Assignation intercepted" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap \t" << name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap \tI am: " << this->name << "(DiamondTrap), aka " << this->ClapTrap::name << "(ClapTrap)" << std::endl;
}
