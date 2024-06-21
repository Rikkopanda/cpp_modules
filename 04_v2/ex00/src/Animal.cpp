/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:56:57 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){std::cout << "Animal default constructor called" << std::endl; type = "Animal";}
Animal::Animal(std::string	type){std::cout << "Animal " << type << " parameter constructor called" << std::endl; this->type = type;}
Animal::Animal(Animal &src){std::cout << "Animal copy constructor operator called" << std::endl; *this = src;}
Animal &Animal::operator=(const Animal &src)
{
	std::cout << "src = " << src.type << std::endl;
	std::cout << "this = " << this->type << std::endl;
	std::cout << "Animal Assignation operator called" << std::endl;
	type = src.type;
	return *this;
}
Animal::~Animal(){std::cout << "Animal " << type << " destructor called" << std::endl;}
void	Animal::makeSound() const{std::cout << "beep beep\n" << std::endl;}
std::string Animal::getType() const{return this->type;}

//----------------------------------------------------

Cat::Cat(){std::cout << "Cat default constructor called" << std::endl; type = "Cat";}
Cat::Cat(std::string	type){std::cout << "Cat " << type << " parameter constructor called" << std::endl; this->type = type;}
Cat::Cat(Cat &src):Animal(){std::cout << "Cat copy constructor operator called" << std::endl; type = src.type;}
Cat &Cat::operator=(const Cat &src){std::cout << "Cat Assignation operator called" << std::endl; this->type = src.type;	return *this;}
Cat::~Cat(){std::cout << "Cat " << type << " destructor called" << std::endl;}
void	Cat::makeSound() const{std::cout << type << ": meaaaouw\n" << std::endl;}

//----------------------------------------------------

Dog::Dog(){std::cout << "Dog default constructor called" << std::endl; type = "Dog";}
Dog::Dog(std::string	type){std::cout << "Dog " << type << " parameter constructor called" << std::endl; this->type = type;}
Dog::Dog(Dog &src):Animal(src){std::cout << "Dog copy constructor operator called" << std::endl; type = src.type;}
Dog &Dog::operator=(const Dog &src){std::cout << "Dog Assignation operator called" << std::endl; this->type = src.type;	return *this;}
Dog::~Dog(){std::cout << "Dog " << type << " destructor called" << std::endl;}
void	Dog::makeSound() const{std::cout << type << ": wOOOOOOFFFF\n" << std::endl;}

//----------------------------------------------------

WrongAnimal::WrongAnimal(){std::cout << "WrongAnimal default constructor called" << std::endl; type = "WrongAnimal";}
WrongAnimal::WrongAnimal(std::string	type){std::cout << "WrongAnimal " << type << " parameter constructor called" << std::endl; this->type = type;}
WrongAnimal::WrongAnimal(WrongAnimal &src){std::cout << "WrongAnimal copy constructor operator called" << std::endl; *this = src;}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src){std::cout << "WrongAnimal Assignation operator called" << std::endl; this->type = src.type;	return *this;}
WrongAnimal::~WrongAnimal(){std::cout << "WrongAnimal " << type << " destructor called" << std::endl;}
void	WrongAnimal::makeSound() const{std::cout << type << ": WrongAnimal sound\n" << std::endl;}
std::string WrongAnimal::getType() const{return this->WrongAnimal::type;}

//----------------------------------------------------

WrongCat::WrongCat(){std::cout << "WrongCat default constructor called" << std::endl; type = "WrongCat";}
WrongCat::WrongCat(std::string	type){std::cout << "WrongCat " << type << " parameter constructor called" << std::endl; this->type = type;}
WrongCat::WrongCat(WrongCat &src):WrongAnimal(src){std::cout << "WrongCat copy constructor operator called" << std::endl; *this = src;}
WrongCat &WrongCat::operator=(const WrongCat &src){std::cout << "WrongCat Assignation operator called" << std::endl; this->type = src.type;	return *this;}
WrongCat::~WrongCat(){std::cout << "WrongCat " << type << " destructor called" << std::endl;}
void	WrongCat::makeSound() const{std::cout << type << ": WrongCat sound\n" << std::endl;}
