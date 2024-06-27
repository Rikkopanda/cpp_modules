/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:49:29 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/27 13:03:25 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern(void)
{
	std::cout << "Intern has been default constructed" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern has been destructed" << std::endl;
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

// AForm* CreateWrongInputForm(std::string target)
// {
// 	AForm *nieuwe;

// 	nieuwe = new AForm(target);
// 	return nieuwe;
// }

/**
 * if wrong imput given
*/
AForm* Intern::makeForm(std::string form_type_name, std::string target) const
{
	int i = 0;

	while (formCreationTable[i].formTypeName != form_type_name && i != 3)
	{
		i++;
	}
	if (i == 3)
	{
		// std::cout << "wrong input given to makeForm, " << std::endl;
		throw Wrong_Creation_Request_Exception("wrong input given");
	}
	AForm *form = formCreationTable[i].createFunc(target);
	return form;
}

Intern::Wrong_Creation_Request_Exception::Wrong_Creation_Request_Exception(const char *msg)
{
	this->message = msg;
}

const char *Intern::Wrong_Creation_Request_Exception::what() const noexcept
{
	return message.c_str();
}