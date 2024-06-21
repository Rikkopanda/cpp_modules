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
#include "FragTrap.hpp"
#include <limits>

int main(void)
{
	std::cout << Green << "tesing claptrap" << Default_restore << std::endl;

	FragTrap	a("Bert");
	FragTrap	b("hallo");

	b.attack("Johan");
	b.beRepaired(3);
	a.takeDamage(155);
	a.attack("Dohan");
	b.highFivesGuys();
	b.highFivesGuys();
	a.highFivesGuys();
	return 0;
}
