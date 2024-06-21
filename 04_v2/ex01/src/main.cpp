/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:23:01 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 14:05:28 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Animal.hpp"
#include <limits>

/**
 * https://www.quora.com/Why-do-we-write-delete-than-new-in-copy-assignment-operator-overload-if-our-class-has-a-member-that-is-a-pointer-to-another-object-in-C
*/
int main()
{
	_Animal**	array = new _Animal*[10];
	std::cout << "____________________" << std::endl;
	Cat			cat_example("cat 1");
	std::cout << "____________________" << std::endl;
	Dog			dog_example("woefie");
	std::cout << "____________________" << std::endl;
	Cat			catcopy = cat_example;
	std::cout << "____________________" << std::endl;

	{
		_Animal	*stdAnimal = new _Animal("hoi");
		stdAnimal->setBrain();
		_Animal	*stdAnimal2 = new _Animal(*stdAnimal);
		_Animal	*moved_example = new _Animal;

		stdAnimal->BrainScan();
		stdAnimal2->BrainScan();
		stdAnimal2->moveBrain(moved_example);
		std::cout << "____________________" << std::endl;

		delete stdAnimal2;
		delete stdAnimal;
		delete moved_example;
	}
	std::cout << "____________________" << std::endl;


	{
		Dog	*stdDog = new Dog("hoi");
		stdDog->setBrain();
		Dog	*stdDog2 = new Dog(*stdDog);
		Dog	*moved_example = new Dog;

		stdDog->BrainScan();
		stdDog2->BrainScan();
		stdDog2->moveBrain(moved_example);
		std::cout << "____________________" << std::endl;

		delete stdDog2;
		delete stdDog;
		delete moved_example;
	}

	std::cout << "____________________" << std::endl;
	for (int i = 0; i < 4; i++)
		array[i] = new Cat();
	std::cout << "____________________" << std::endl;
	std::cout << "making new cat from example" << RESET << std::endl;
	array[4] = new Cat(cat_example);
	array[4]->setBrain();
	std::cout << "____________________" << std::endl;
	for (int i = 5; i < 9; i++)
		array[i] = new Dog();
	std::cout << "making new dog from example" << RESET << std::endl;
	std::cout << "____________________" << std::endl;
	array[9] = new Dog(dog_example);
	array[3]->BrainCopy(array[4]->getBrain());
	array[3]->BrainScan();
	array[4]->BrainScan();
	array[4]->_Animal::setBrain();
	array[4]->_Animal::BrainScan();
	Cat			another_copy = *(Cat *)array[9];
	std::cout << "____________________" << std::endl;
	std::cout << "array objects destructors:" << std::endl;
	for (int i = 0; i < 10; i++)
		delete array[i];
	delete[] array;
	std::cout << "____________________" << std::endl;
	std::cout << "stack objects destructors:" << std::endl;

	return 0;
}
