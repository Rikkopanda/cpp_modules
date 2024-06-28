/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/28 08:58:10 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	Data data;
	uintptr_t integer;

	integer = Serializer::serialize(&data);

	std::cout << "integer: " << integer << std::endl;
	std::cout << "address: " << &data << std::endl;

	Data *convertedback;
	convertedback = Serializer::deserialize(integer);
	std::cout << "ptr: " << convertedback << std::endl << std::endl;

	const Data data2;
	const uintptr_t integer2 = (Serializer::serialize(const_cast<Data *>(&data2)));
	std::cout << "integer: " << integer << std::endl;
	std::cout << "address: " << &data << std::endl;
	const Data *convertedback2 = Serializer::deserialize(integer2);
	std::cout << "ptr: " << convertedback2 << std::endl << std::endl;

	volatile Data data3;
	volatile uintptr_t integer3 = (Serializer::serialize(const_cast<Data *>(&data3)));
	std::cout << "integer: " << integer3 << std::endl;
	std::cout << "address: " << const_cast<Data *>(&data3) << std::endl;
	volatile Data *convertedback3 = Serializer::deserialize(integer3);
	std::cout << "ptr: " << const_cast<Data *>(convertedback3) << std::endl << std::endl;
}