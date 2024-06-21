
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:51:29 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/05/08 10:26:04 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Amateria.hpp"
#include "IMateriaSource.hpp"

/**
 * https://github.com/achrafelkhnissi/CPP_Modules/tree/master/Module_04
 * explanation
 * https://www.geeksforgeeks.org/cpp-program-to-create-an-interface/
*/
int main()
{
	std::cout << "print bool = " << PRINT_ALL << std::endl;
	Ice		*test = new Ice("Test");
	{
		Character	*Bob = new Character("Bob");
		Character	*Bob_2 = new Character(*Bob);

		*Bob_2 = *Bob;
		test->use(*Bob);
		delete Bob;
		delete Bob_2;
	}
	if (PRINT_ALL == TRUE)
		std::cout << std::endl << "____________________________________________" << std::endl;
	{
		AMateria	*Mat_ptr;
		Ice			*Icy_ptr0;
		Ice 		*Icy_ptr1 = new Ice("ice0");
		Character	Jhon("Joe");
		Character	Bennie("Ben");
		Cure 		*healer = new Cure("healer1");
		Cure 		*healer_clone = (Cure *)healer->clone();

		Icy_ptr0 = new Ice();
		Mat_ptr = Icy_ptr0;
		if (PRINT_ALL == TRUE)
			std::cout << Mat_ptr->getType() << std::endl;
		Jhon.equip(Mat_ptr);
		Jhon.equip(Icy_ptr1);
		Jhon.use(0, Bennie);
		Jhon.unequip(1);
		Jhon.use(1, Jhon);
		Jhon.use(2, Jhon);
		Jhon.use(3, Jhon);
		Bennie.equip(healer);
		Bennie.equip(healer_clone);
		Jhon.unequip(11);
		Bennie.use(0, Bennie);
		if (PRINT_ALL == TRUE)
			std::cout << "*\twhat type is healer:" << healer->getType() << std::endl;
		if (PRINT_ALL == TRUE)
			std::cout << "*\twhat type is healer_clone:" << healer_clone->getType() << std::endl;
		Bennie.use(1, Bennie);
		delete Icy_ptr1;
	}
	if (PRINT_ALL == TRUE)
		std::cout << std::endl << "____________________________________________" << std::endl;
	{
		Ice *clone_test = (Ice *)test->clone();

		delete clone_test;
	}
	if (PRINT_ALL == TRUE)
		std::cout << std::endl << "____________________________________________" << std::endl;
	{
		Character	*Chtr_ptr;
		Character	*Brian_chtr;
		Ice			*Icy_ptr2 = new Ice("ice1");
		Ice 		*Icy_normal2 = new Ice("ice2");

		Brian_chtr = new Character("Brian");
		Chtr_ptr = new Character("Bobby");
		Chtr_ptr->equip((AMateria *)Icy_ptr2);
		Chtr_ptr->equip((AMateria *)Icy_normal2);
		Chtr_ptr->use(0, *Brian_chtr);
		Chtr_ptr->use(1, *Brian_chtr);
		Chtr_ptr->use(5, *Brian_chtr);
		if (PRINT_ALL == TRUE)
			std::cout << std::endl << "____________________________________________" << std::endl;
		MateriaSource	*Msource = new MateriaSource;

		Msource->learnMateria(new Ice("brrrrr cold"));
		Msource->learnMateria(new Cure("medic !"));

		AMateria *CreatedIcy = Msource->createMateria("ice1");
		AMateria *CreatedIcy2 = Msource->createMateria("ice2");
		
		Chtr_ptr->equip((AMateria *)CreatedIcy);
		Chtr_ptr->equip((AMateria *)CreatedIcy2);

		Chtr_ptr->use(2, *Brian_chtr);
		Chtr_ptr->use(3, *Brian_chtr);

		delete Msource;
		delete Brian_chtr;
		delete Chtr_ptr;
	}
	delete test;
}
// Chtr_ptr->equip(dynamic_cast<AMateria *>(&Icy_ptr2));
// Chtr_ptr->equip(dynamic_cast<AMateria *>(&Icy_normal2));
