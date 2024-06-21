/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:57:49 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstdio>
/*
	Virtual destructor:
	A virtual destructor is used to free up the memory space allocated by 
	the derived class object or instance while deleting instances of the derived
	class using a base class pointer object. A base or parent class destructor
	use the virtual keyword that ensures both base class and the derived class 
	destructor will be called at run time, but it called the derived class first
	and then base class to release the space occupied by both destructors.

	Every destructor down gets called no matter what. virtual makes sure it
	starts at the top instead of the middle.

	Virtual destructors are useful when you might potentially delete an instance 
	of a derived class through a pointer to base class:

	https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
*/
class Animal {
	protected:
		std::string		type;
	public:
		Animal();
		Animal(std::string	name);
		Animal(Animal &src);
		Animal& operator=(const Animal &src);
		virtual ~Animal();
		virtual void	makeSound() const;
		std::string	getType() const;
};

class Dog : public Animal{
	public:
		Dog();
		Dog(std::string	name);
		Dog(Dog &src);
		Dog& operator=(const Dog &src);
		~Dog();
		void	makeSound() const;
};

class Cat : public Animal{
	public:
		Cat();
		Cat(std::string	name);
		Cat(Cat &src);
		Cat& operator=(const Cat &src);
		~Cat();
		void	makeSound() const;
};

class WrongAnimal{
	protected:
		std::string		type;
	public:
		WrongAnimal();
		WrongAnimal(std::string	name);
		WrongAnimal(WrongAnimal &src);
		WrongAnimal& operator=(const WrongAnimal &src);
		virtual ~WrongAnimal();
		/*
			https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-cpp/
			what function gets called depends on the actual object type in the program,
			not the the type of class ptr, which would be declared at compile time.
			Now it is determined late at runtime.
		*/
		virtual void	makeSound() const;
		std::string	getType() const;
};

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(std::string	name);
		WrongCat(WrongCat &src);
		WrongCat& operator=(const WrongCat &src);
		~WrongCat();
		void	makeSound() const;
};

/*
	https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-cpp/
*/
#endif
