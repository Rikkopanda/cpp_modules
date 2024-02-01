/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/31 16:23:02 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl walks into donut shop" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl got kicked out" << std::endl;	
}

void Harl::debug( void )
{
	std::cout << "I love donuts, I think am going to order some chocolate and fruit donuts" << std::endl;	
}

void Harl::info( void )
{
	std::cout << "I can't believe doctor says I should'nt eat them.. Hey sir I asked for 3 donuts, you gave 2 " << std::endl;	
}

void Harl::warning( void )
{
	std::cout << "I don't think you understand urgency I need 3 not 2, also hurry I have to catch the bus!" << std::endl;	
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I will never eat donuts again!!!" << std::endl;	
}

typedef void (Harl::*member_f_ptrs[4])(void);

void Harl::complain( std::string level )
{
	member_f_ptrs f_ptrs = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*f_ptrs[i])();
		}
	}
}