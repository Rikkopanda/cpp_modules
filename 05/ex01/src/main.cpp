/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/07/01 17:52:55 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include "text_colors.hpp"

int main(void)
{
	std::cout << GREEN << std::endl;
	Bureaucrat	Obama("Obama", 88);
	Form		law_proposal("bill 56", 88, 89);
	std::cout << RESET << std::endl;

	std::cout << &law_proposal << std::endl;

	try
	{
		Obama.IncrementGrade();
		Obama.IncrementGrade();
		Obama.IncrementGrade();
	} catch (const::Bureaucrat::GradeTooHighException &exc) // pass by reference so its not copied
	{
		std::cout << RED << "Increment caught exception: " << exc.what() << RESET << std::endl;
	} catch (const::Bureaucrat::GradeTooLowException &exc) // pass by reference so its not copied
	{
		std::cout << RED << "Increment caught exception: " << exc.what() << RESET << std::endl;
	} catch (...) { std::cout << "Increment default exception: " << std::endl; }
	std::cout << &Obama << std::endl;
	Obama.signForm(&law_proposal);
	law_proposal.beSigned(Obama);
	Obama.signForm(&law_proposal);

	std::cout << &law_proposal << std::endl;

	{
		std::cout << BLUE << std::endl;
		Bureaucrat	Trump("Trump", 2);
		Form		law_proposal("bill 66", 66, 66);
		std::cout << RESET << std::endl;
	
		std::cout << &law_proposal << std::endl;

		try
		{
			Trump.IncrementGrade();
			Trump.IncrementGrade();
			Trump.IncrementGrade();
		} catch (const::Bureaucrat::GradeTooHighException &exc) // pass by reference so its not copied
		{
			std::cout << RED << "Increment caught exception: " << exc.what() << RESET << std::endl;
		} catch (const::Bureaucrat::GradeTooLowException &exc) // pass by reference so its not copied
		{
			std::cout << RED << "Increment caught exception: " << exc.what() << RESET << std::endl;
		} catch (...) { std::cout << "Increment default exception: " << std::endl; }

		std::cout << &Trump << std::endl;
		Trump.signForm(&law_proposal);
		law_proposal.beSigned(Trump);
		Trump.signForm(&law_proposal);
		std::cout << &law_proposal << std::endl;
	}


}
