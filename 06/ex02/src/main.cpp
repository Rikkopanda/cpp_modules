/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/28 10:02:55 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>

void identify(Base *p)
{
	std::cout << p->TypeName() << std::endl;
}

void identify(Base& p)
{
	std::cout << p.TypeName() << std::endl;
}

void check_type_by_way_of_casting(Base *ptr)
{
	if (dynamic_cast<A *>(ptr))
		std::cout << "Actual type: A" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "Actual type: B" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "Actual type: C" << std::endl;
}

int main(int argc, char **argv)
{
	Base	*something = new A();
	A		directA;
	B		directB;
	C		directC;
	Base	*ptr_to_block_var;

	ptr_to_block_var = &directC;
	identify(something);
	identify(*something);
	identify(directA);
	identify(ptr_to_block_var);
	check_type_by_way_of_casting(ptr_to_block_var);
	
	delete something;
}
