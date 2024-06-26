/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/26 11:24:29 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text_colors.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
// #include "Intern.hpp"

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

typedef AForm *(* t_func_ptr)(std::string form_type_request_name, std::string target);

typedef struct s_func_table
{
	t_func_ptr	fptr;
	std::string matching_str;
} t_func_table;


int main(void)
{
	Bureaucrat	Obama("Obama", 33);
	AForm		*law_proposal;
	ShrubberyCreationForm form("bill 56");
	AForm		*haahiahdwhiuahd = new RobotomyRequestForm("robocop");

	ShrubberyCreationForm formcpy;
	std::cout << BLUE;
	Bureaucrat	obamacpy;

	law_proposal = &form;
	obamacpy = Obama;
	formcpy = form;
	
	// haahiahdwhiuahd = law_proposal;
	std::cout << RESET;
	std::cout << RED;



	try{
		haahiahdwhiuahd->execute(Obama);
	} catch (const::AForm::GradeTooHighException &exc)
	{
		std::cout << "Execute caught exception: " << exc.what() << std::endl;
	} catch (const::AForm::GradeTooLowException &exc)
	{
		std::cout << "Execute caught exception: " << exc.what() << std::endl;
	}catch (const::AForm::FormIsNotToBeSignedException &exc)
	{
		std::cout << "Execute caught exception: " << exc.what() << std::endl;
	}

	std::cout << RESET;
	std::cout << GREEN;

	// Intern stagair;
	// AForm *doorstagairgemaakt = stagair.makeForm(ROBOTOMY_REQUEST, "thuis");
	// std::cout << doorstagairgemaakt << std::endl;
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
	Obama.signForm(law_proposal);
	law_proposal->beSigned(Obama);
	Obama.signForm(law_proposal);

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

	try{
		law_proposal->execute(Obama);
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


	try{
		Obama.executeForm(*law_proposal);
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
	std::cout << law_proposal << std::endl;
	std::cout << &Obama << std::endl;

	delete haahiahdwhiuahd;
}
