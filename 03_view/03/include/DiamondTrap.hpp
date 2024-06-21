/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:57:49 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>
#include <cstdio>

/**	• Hit points (FragTrap) 100
	• Energy points (ScavTrap) 50
	• Attack damage (FragTrap) 30
	• attack() (Scavtrap)

	either manually hard code it

	or have 2 instances of ClapTrap; from Scav or Frag inherited
	and use scope::var to define of which instance to use.

*/
class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string		name;
	public:
		DiamondTrap(std::string	name);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap& operator=(const DiamondTrap &src);
		// void ScavTrap::attack();
		using ScavTrap::attack;
		~DiamondTrap();
		void whoAmI();
};

#endif