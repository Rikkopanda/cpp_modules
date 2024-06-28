/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/27 10:02:45 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Base.hpp"
class A : public Base {	
	public:
		std::string TypeName();
		A();
		~A();
};

#endif