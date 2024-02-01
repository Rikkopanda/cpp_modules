/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/31 15:09:35 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
  // std::cout << "zombie " << name << " is made" << std::endl;
}

Zombie::Zombie(std::string name)
{
  this->name = name;
  //std::cout << "zombie " << name << " is made" << std::endl;
}

Zombie::~Zombie()
{
  std::cout << name << " is destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
  this->name = name;
}
