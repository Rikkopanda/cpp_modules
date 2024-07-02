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

#include  <random>

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
	std::cout << "identified: " << p->TypeName() << std::endl;
}

void identify(Base& p)
{
	std::cout << "identified: " << p.TypeName() << std::endl;
}


enum e_for_class_select{
	A_case,
	B_case,
	C_case
};

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