/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/27 13:12:29 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text_colors.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

void	interntests()
{
	Intern stagair;

	std::cout << GREEN;
	AForm *doorstagairgemaakt = stagair.makeForm(SCHRUB_REQUEST, "thuis");
	std::cout << doorstagairgemaakt << std::endl;
	delete doorstagairgemaakt;
	std::cout << RESET;

	std::cout << BLUE;
	doorstagairgemaakt = stagair.makeForm(PRESI_PARDON_REQUEST, "thuis");
	std::cout << doorstagairgemaakt << std::endl;
	delete doorstagairgemaakt;
	std::cout << RESET;

	std::cout << RED;
	doorstagairgemaakt = stagair.makeForm(ROBOTOMY_REQUEST, "thuis");
	std::cout << doorstagairgemaakt << std::endl;
	delete doorstagairgemaakt;
	std::cout << RESET;

	std::cout << YELLOW;
	doorstagairgemaakt = stagair.makeForm("wrong request", "thuis");
	std::cout << doorstagairgemaakt << std::endl;
	delete doorstagairgemaakt;
	std::cout << RESET;
}


int main(void)
{
	Bureaucrat	Obama("Obama", 33);

	try {
		interntests();
	} catch (Intern::Wrong_Creation_Request_Exception &e)
	{
		std::cout << "interntests: " << e.what() << std::endl;
		std::cout << RESET;
	}

	std::cout << BLUE;
	Intern stagair;
	AForm	*doorstagairgemaakt = stagair.makeForm(PRESI_PARDON_REQUEST, "thuis");
	std::cout << doorstagairgemaakt << std::endl;
	std::cout << RESET;

	try
	{
		Obama.IncrementGrade();
		Obama.IncrementGrade();
		Obama.IncrementGrade();
	} catch (const::Bureaucrat::GradeTooHighException &exc)
	{
		std::cout << "Increment caught exception: " << exc.what() << std::endl;
	} catch (const::Bureaucrat::GradeTooLowException &exc)
	{
		std::cout << "Increment caught exception: " << exc.what() << std::endl;
	}

	std::cout << &Obama << std::endl;
	Obama.signForm(doorstagairgemaakt);
	doorstagairgemaakt->beSigned(Obama);
	Obama.signForm(doorstagairgemaakt);

	try
	{
		Obama.DecrementGrade();
		Obama.DecrementGrade();
		Obama.DecrementGrade();
	} catch (const::Bureaucrat::GradeTooHighException &exc)
	{
		std::cout << "Increment caught exception: " << exc.what() << std::endl;
	} catch (const::Bureaucrat::GradeTooLowException &exc)
	{
		std::cout << "Increment caught exception: " << exc.what() << std::endl;
	}
	std::cout << BLUE;

	try{
		doorstagairgemaakt->execute(Obama);
	} catch (const::AForm::GradeTooHighException &exc)
	{
		std::cout << "Execute caught exception: " << exc.what() << std::endl;
	} catch (const::AForm::GradeTooLowException &exc)
	{
		std::cout << "Execute caught exception: " << exc.what() << std::endl;
	} catch (const::AForm::FormIsNotToBeSignedException &exc)
	{
		std::cout << "Execute caught exception: " << exc.what() << std::endl;
	}
	std::cout << RESET;


	try{
		Obama.executeForm(*doorstagairgemaakt);
	} catch (const::AForm::GradeTooHighException &exc)
	{
		std::cout << "Execute caught exception: " << exc.what() << std::endl;
	} catch (const::AForm::GradeTooLowException &exc)
	{
		std::cout << "Execute caught exception: " << exc.what() << std::endl;
	} catch (const::AForm::FormIsNotToBeSignedException &exc)
	{
		std::cout << "Execute caught exception: " << exc.what() << std::endl;
	}

	std::cout << BLUE;
	std::cout << doorstagairgemaakt << std::endl;
	std::cout << RESET;

	std::cout << &Obama << std::endl;

	std::cout << BLUE;
	delete doorstagairgemaakt;
	std::cout << RESET;
}
