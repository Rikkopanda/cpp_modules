/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:57:49 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>
#include <cstdio>

class ScavTrap: public ClapTrap {
	private:
		unsigned int	guarding_bool;
	public:
		ScavTrap(std::string	name);
		ScavTrap(const ScavTrap &src);
		ScavTrap& operator=(const ScavTrap &src);
		~ScavTrap();
		void	attack(const std::string& target) override;
		void guardGate();
};

#endif