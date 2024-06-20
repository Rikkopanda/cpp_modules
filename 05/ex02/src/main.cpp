/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/20 09:19:25 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Bureaucrat	Obama("Obama", 5);
	AForm		*law_proposal;
	ShrubberyCreationForm form("bill 56");
	law_proposal = &form;

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
	std::cout << law_proposal << std::endl;
}
