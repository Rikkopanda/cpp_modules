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

/**
 * making sure that ClapTrap base class is inherited only
 * once in the diamond hiearchy structure.
 * This is done with virtual.
 * 
 * otherwise there would be 2 instances of Claptrap in final diamondclass
 * 
*/
class FragTrap: virtual public ClapTrap {
	protected:
		unsigned int	high_five_request_bool;
	public:
		FragTrap();
		FragTrap(std::string	name);
		FragTrap(const FragTrap &src);
		FragTrap& operator=(const FragTrap &src);
		void	attack(const std::string& target);
		~FragTrap();
		void highFivesGuys(void);
};

#endif
