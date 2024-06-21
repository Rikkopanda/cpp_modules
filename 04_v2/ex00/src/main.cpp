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

int main()
{
	{
		Animal* meta = new Animal("bennie");
		Animal* meta2 = new Animal(*meta);
		Dog*	dog = new Dog("blaf");
		Animal* j = new Dog(*dog);
		Animal* i = new Dog();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << meta << std::endl;
		// std::cout << meta2 << std::endl;

		*meta = *meta2;
		*i = *j;
		*i = *meta;

		std::cout << std::endl << meta << std::endl;
		// std::cout << meta2 << std::endl;

		const WrongAnimal* wrong_animal = new WrongAnimal();
		const WrongCat* wrong_cat = new WrongCat();

		j->makeSound();
		wrong_animal->makeSound();
		wrong_cat->makeSound();

		delete meta;
		delete meta2;
		delete j;
		delete i;
		delete dog;
		delete wrong_animal;
		delete wrong_cat;
	}
	{
		WrongAnimal* Base_ptr = new WrongCat("bonnie");

		delete Base_ptr;
	}
	return 0;
}