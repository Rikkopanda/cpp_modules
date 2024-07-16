/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:54:25 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/03 10:40:27 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"


Serializer::Serializer(void)
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "Serializer default constructor called" << std::endl;
	#endif
}

Serializer::Serializer(std::string useless_input)
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "Serializer parameter constructor called with: " << useless_input << std::endl;
	#endif
	std::cout << useless_input << std::endl;
}

Serializer::Serializer(Serializer &src)
{
	(void)src;
	#ifdef PRINT_MORE_INFO
	 std::cout << "Serializer copy constructor called" << std::endl;
	#endif
}

Serializer::~Serializer(void)
{
	#ifdef PRINT_MORE_INFO
	 std::cout << "Serializer destructor called" << std::endl;
	#endif
}

Serializer& Serializer::operator=(Serializer &src)
{
	(void)src;
	#ifdef PRINT_MORE_INFO
	 std::cout << "Serializer assignment operator called" << std::endl;
	#endif
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

// uintptr_t Serializer::serialize(const Serializer* ptr)
// {
// 	return reinterpret_cast<uintptr_t>(const_cast<Serializer *>(ptr));
// }

// Serializer* Serializer::deserialize(const uintptr_t raw)
// {
// 	// uintptr_t raw_p2 = const_cast<uintptr_t>(raw);
// 	return reinterpret_cast<Serializer *>(const_cast<uintptr_t>(raw));
// }
