/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:23:01 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/31 15:10:52 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

int main() {

  Zombie* ptr = zombieHorde(4, "Jack");

  for (int i = 0; i < 4; i++)
    ptr[i].announce();

  delete[] ptr;

  return 0;
}

//Person person1("Rajat");
//Person person2 = person1
// --- this copies the object for a new object. they are identical in attributesZ
// --- but not the same object.
// --- however with pointers this is otherwize