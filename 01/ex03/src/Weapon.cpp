/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rik <rik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/30 15:42:15 by rik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

// Weapon::Weapon()
// {
// 	type = "fists";
// 	std::cout << "Weapon " << type << " is made" << std::endl;
// }

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "Weapon " << type << " is made" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << type << " weapon is destroyed" << std::endl;
}
