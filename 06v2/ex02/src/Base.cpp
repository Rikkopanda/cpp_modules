/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CreBaseted: 2024/06/27 21:00:56 by rikverhoeve       #+#    #+#             */
/*   UpdBaseted: 2024/06/28 09:14:02 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "text_colors.hpp"
#include <exception>
#include <random>

std::string Base::TypeName()
{
	return "Base";
}

Base::Base()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "Base constructor called" << RESET << std::endl;
	#endif
}

Base::~Base()
{
	#ifdef PRINT_MORE_INFO
	 std::cout << DARKGREY << "Base destructor called" <<  RESET << std::endl;
	#endif
}


void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "identified: pointer A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "identified: pointer B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "identified: pointer C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "identified: reference A" << std::endl;
	}catch (std::exception &exc)
	{
		std::cout << "exception caught: " << exc.what() << std::endl;
	}

	try
	{
		dynamic_cast<B &>(p);
		std::cout << "identified: reference B" << std::endl;
	}catch (std::exception &exc)
	{
		std::cout << "exception caught: " << exc.what() << std::endl;
	}

	try
	{
		dynamic_cast<C &>(p);
		std::cout << "identified: reference C" << std::endl;
	}catch (std::exception &exc)
	{
		std::cout << "exception caught: " << exc.what() << std::endl;
	}
}

/*
	https://cplusplus.com/reference/random/mersenne_twister_engine/
*/
Base *Base::generate(void)
{
	Base	*made;

	std::random_device rd;
	std::uniform_int_distribution<int> distribution(0, 2);
	std::mt19937 generator(rd());
	switch (distribution(generator))
	{
	case A_case:
		made = new A();
		break;
	case B_case:
		made = new B();
		break;
	case C_case:
		made = new C();
		break;
	}
	return made;
}
// std::cout << "min" << generator.min() << std::endl;
// std::cout << "max" << generator.max() << std::endl;
// for (int i = 0; i < 10; i++)
// {
// 	std::cout << "nbr:" << i << " random: " << distribution(generator) << std::endl;
// }