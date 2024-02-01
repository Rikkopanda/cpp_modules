/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:02 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/31 15:07:15 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	allocated on heap.
	Zombie() constructor is at: new Zombie[n]
	___________________
	Other ways to make object arrays:

	Test obj[] = { Test(1, 1), Test(2, 2), Test(3, 3) };
	______

	Use malloc(): To avoid the call of a non-parameterized constructor
	______

	// allocating ptr to ptr array
	Test** arr = new Test*[N];

	// calling constructor for each index
	// of array using new keyword
	for (int i = 0; i < N; i++) {
		arr[i] = new Test(i, i + 1);
	}
	______

	// vector of type Test class
	vector<Test> v;

	// inserting object at the end of vector
	for (int i = 0; i < N; i++)
		v.push_back(Test(i, i + 1));
*/
Zombie* zombieHorde(int N, std::string name )
{
	Zombie *z_arr = new Zombie[N]();

	for (int i = 0; i < N; i++)
	{
		z_arr[i].setName(name);
	}

	// std::cout << name << std::endl;
	// for (int i = 0; i < n; i++)
	// {
	// 	z_ptr[i].name = name;
	// }
	// std::string test;
	// std::cin >> test;
	return (z_arr);
}
/*

*/