/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:23:01 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 14:05:28 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <limits>

int main(void)
{
	std::cout << Green << "tesing claptrap" << Default_restore << std::endl;

	DiamondTrap	a("Bert");
	DiamondTrap	b("Ernie");
	DiamondTrap	c(b);

	// DiamondTrap	*ptr;

	// ptr = &c;
	// c = *ptr;
	std::cout << "_________________________" << std::endl;
	b.attack("Johan");
	b.beRepaired(30);
	a.attack("Dohan");
	a.attack("Dohan");
	a.attack("Dohan");
	a.attack("Dohan");
	b.highFivesGuys();
	std::cout << "_________________________" << std::endl;
	// c.highFivesGuys();
	// b.highFivesGuys();
	// a.highFivesGuys();
	a.whoAmI();
	b.whoAmI();
	c.whoAmI();
	std::cout << "_________________________" << std::endl;

	c = a;
	a.whoAmI();
	b.whoAmI();
	c.whoAmI();
	std::cout << "_________________________" << std::endl;

	// a.takeDamage(155);
	// c.beRepaired(145);
	// c.attack("Dohan");
	// a.attack("Dohan");
	return 0;
}
