/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/24 18:26:57 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Harl_HPP
# define Harl_HPP

#include <iostream>
#include <string>

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );  
	public:
		Harl(void);
		~Harl(void);
		void complain( std::string level );
};

#endif