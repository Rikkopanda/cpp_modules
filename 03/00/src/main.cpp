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
#include <limits>


int main(void)
{
	std::cout << "\033[34mtesing claptrap\033[0m" << std::endl;

	ClapTrap	a("Bert");
	ClapTrap	b("hallo");

	b.attack("Johan");
	b.beRepaired(3);
	a.takeDamage(5);
	a.attack("B:wohan");

	return 0;
}
