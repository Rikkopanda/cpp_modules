/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/07/02 20:09:13 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "identify.hpp"
#include <iostream>
#include <string>

void check_type_by_way_of_casting(Base *ptr)
{
	if (dynamic_cast<A *>(ptr))
		std::cout << "dynamtic cast check: A" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "dynamtic cast check: B" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "dynamtic cast check: C" << std::endl;
}

void checkRandom()
{
	std::cout << std::endl;
	std::cout << std::endl;
	Base *R = Base::generate();
	std::cout << "generated: " << R->TypeName() << std::endl;

	identify(R);
	check_type_by_way_of_casting(R);
}


int main()
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

	checkRandom();
	delete something;
}
