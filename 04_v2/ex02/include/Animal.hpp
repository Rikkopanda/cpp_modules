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

#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>
# include <string>
# include <cstdio>

#define RESET "\033[0m"
#define Black "\033[0;30m"
#define Red "\033[0;31m"
#define Green "\033[0;32m"
#define Yellow "\033[0;33m"
#define Blue "\033[0;34m"
#define Purple "\033[0;35m"
#define Cyan "\033[0;36m"
#define White "\033[0;37m"

#define LIGHT_GRAY "\033[37m"
#define DARK_GRAY "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"

class Brain{
	public:
		std::string	ideas[100];
		Brain();
		Brain(Brain &src);
		~Brain();
		Brain& operator=(const Brain &src);
};

class _Animal{
	protected:
		std::string		type;
	public:
		_Animal();
		_Animal(_Animal &src);
		_Animal& operator=(const _Animal &src);
		virtual ~_Animal() = 0;
		std::string	getType() const;
		virtual void BrainCopy(Brain *src){(void)src; std::cout << "abstract class, so function not usefull" << std::endl;};
		virtual Brain *getBrain(){std::cout << "abstract class, so function not usefull" << std::endl; return(nullptr);};
		virtual void setBrain(){std::cout << "abstract class, so function not usefull" << std::endl;};
		virtual void BrainScan(){std::cout << "abstract class, so function not usefull" << std::endl;};
};

class Dog : public _Animal{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(std::string	name);
		Dog(Dog &src);
		Dog& operator=(const Dog &src);
		void moveBrain();
		void setBrain();
		void BrainCopy(Brain *src);
		Brain *getBrain();
		void BrainScan();
		~Dog();
		void	makeSound() const;
};

class Cat : public _Animal{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(std::string	name);
		Cat(Cat &src);
		Cat& operator=(const Cat &src);
		void BrainCopy(Brain *src);
		void moveBrain();
		void setBrain();
		Brain *getBrain();
		void BrainScan();
		~Cat();
		void	makeSound() const;
};

/*
	https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-cpp/
*/
#endif
