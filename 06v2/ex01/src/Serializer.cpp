/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:54:25 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/28 08:12:04 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

// uintptr_t Serializer::serialize(const Data* ptr)
// {
// 	return reinterpret_cast<uintptr_t>(const_cast<Data *>(ptr));
// }

// Data* Serializer::deserialize(const uintptr_t raw)
// {
// 	// uintptr_t raw_p2 = const_cast<uintptr_t>(raw);
// 	return reinterpret_cast<Data *>(const_cast<uintptr_t>(raw));
// }
