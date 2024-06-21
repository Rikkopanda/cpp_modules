/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:57:49 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>
#include <cstdio>

#define FRAG_HIT_PTS 100
#define FRAG_ENERGY_PTS 100
#define FRAG_ATTACK_DAMAGE 30

class FragTrap: public ClapTrap {
	private:
		unsigned int	high_five_request_bool;
	public:
		FragTrap();
		FragTrap(std::string	name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		FragTrap& operator=(const FragTrap &src);
		void	attack(const std::string& target) override;
		void	highFivesGuys(void);
};

#endif