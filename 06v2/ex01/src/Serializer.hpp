/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/27 10:02:45 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
# define Serializer_HPP

#include <iostream>
#include <string>
#include <exception>

class Data;

class Serializer {
	public:
		Serializer(void);
		Serializer(std::string useless_input);
		Serializer(Serializer &src);
		Serializer& operator=(Serializer &src);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		virtual ~Serializer() = 0;
};

#endif