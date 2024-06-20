/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/20 14:37:39 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text_colors.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Bureaucrat	Obama("Obama", 100);
	AForm		*law_proposal;
	ShrubberyCreationForm form("bill 56");

	ShrubberyCreationForm formcpy;
	std::cout << BLUE;
	Bureaucrat	obamacpy;

	law_proposal = &form;
	obamacpy = Obama;
	formcpy = form;
	std::cout << RESET;

	std::cout << &law_proposal << std::endl;
	try
	{
		Obama.IncrementGrade();
		Obama.IncrementGrade();
		Obama.IncrementGrade();
	} catch (const::Bureaucrat::GradeTooHighException &exc)
	{
		std::cerr << "Increment caught exception: " << exc.what() << std::endl;
	} catch (const::Bureaucrat::GradeTooLowException &exc)
	{
		std::cerr << "Increment caught exception: " << exc.what() << std::endl;
	}
	std::cout << &Obama << std::endl;
	Obama.signForm(law_proposal);
	law_proposal->beSigned(Obama);
	Obama.signForm(law_proposal);
	try{
		law_proposal->execute(Obama);
	} catch (const::AForm::GradeTooHighException &exc)
	{
		std::cerr << "Execute caught exception: " << exc.what() << std::endl;
	} catch (const::AForm::GradeTooLowException &exc)
	{
		std::cerr << "Execute caught exception: " << exc.what() << std::endl;
	}
	try{
		Obama.executeForm(*law_proposal);
	} catch (const::AForm::GradeTooHighException &exc)
	{
		std::cerr << "Execute caught exception: " << exc.what() << std::endl;
	} catch (const::AForm::GradeTooLowException &exc)
	{
		std::cerr << "Execute caught exception: " << exc.what() << std::endl;
	}
	std::cout << law_proposal << std::endl;
}
