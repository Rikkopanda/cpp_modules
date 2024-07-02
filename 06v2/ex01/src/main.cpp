/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/07/02 20:12:38 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>
#include "text_colors.hpp"

int main()
{
	Data data;
	uintptr_t integer;


	std::cout << DARKGREY;
	integer = Serializer::serialize(&data);
	std::cout << "integer: " << integer << std::endl;
	std::cout << "address: " << &data << std::endl;
	Data *convertedback;
	convertedback = Serializer::deserialize(integer);
	std::cout << "ptr: " << convertedback << std::endl << std::endl;
	

	std::cout << RESET;
	const Data data2;
	const uintptr_t integer2 = (Serializer::serialize(const_cast<Data *>(&data2)));
	std::cout << GREEN;
	std::cout << "integer: " << integer2 << std::endl;
	std::cout << "address: " << &data2 << std::endl;
	const Data *convertedback2 = Serializer::deserialize(integer2);
	std::cout << "ptr: " << convertedback2 << std::endl << std::endl;


	std::cout << RESET;
	volatile Data data3;
	volatile uintptr_t integer3 = (Serializer::serialize(const_cast<Data *>(&data3)));
	std::cout << BLUE;
	std::cout << "integer: " << integer3 << std::endl;
	std::cout << "address: " << const_cast<Data *>(&data3) << std::endl;
	volatile Data *convertedback3 = Serializer::deserialize(integer3);
	std::cout << "ptr: " << const_cast<Data *>(convertedback3) << std::endl << std::endl;
	std::cout << RESET;

}