/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:49:29 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/22 14:36:45 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

#define CREATE_ROBOTOMYREQUESTFORM 0
#define CREATE_SHRUBBERYCREATIONFORM 1
#define CREATE_PRESIDENTIALPARDONFORM 2


Intern::Intern(void)
{
	// this->formCreationTable[CREATE_ROBOTOMYREQUESTFORM]= CreateRobotomyRequestForm;
	// this->formCreationTable[CREATE_ROBOTOMYREQUESTFORM][1] = new std::string("robotomy request");

	// this->formCreationTable[CREATE_ROBOTOMYREQUESTFORM][0] = CreatePresidentialPardonForm;
	// this->formCreationTable[CREATE_ROBOTOMYREQUESTFORM][1] = new std::string("presidential pardon request");

	// this->formCreationTable[CREATE_ROBOTOMYREQUESTFORM][0] = CreateShrubberyCreationForm;
	// this->formCreationTable[CREATE_ROBOTOMYREQUESTFORM][1] = new std::string("shrubbery creation request");
}

Intern::~Intern(void)
{

}

AForm* CreateRobotomyRequestForm(std::string target)
{
	AForm *nieuwe;

	nieuwe = new RobotomyRequestForm(target);
	return nieuwe;
}

AForm* CreatePresidentialPardonForm(std::string target)
{
	AForm *nieuwe;

	nieuwe = new PresidentialPardonForm(target);
	return nieuwe;
}

AForm* CreateShrubberyCreationForm(std::string target)
{	
	AForm *nieuwe;

	nieuwe = new ShrubberyCreationForm(target);
	return nieuwe;
}

AForm* Intern::makeForm(std::string form_type_name, std::string target) const
{
	int i = 0;

	while (formCreationTable[i].formTypeName != form_type_name && i != 3)
	{
		i++;
	}
	if (i == 3)
		return NULL;
	AForm *form = formCreationTable[i].createFunc(target);
	return form;
}
