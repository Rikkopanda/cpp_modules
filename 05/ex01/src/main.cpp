/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/19 12:51:16 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Bureaucrat	Obama("Obama", 88);
	Form		law_proposal("bill 56", 88, 89);
	std::cout << &law_proposal << std::endl;

	try
	{
		Obama.IncrementGrade();
		Obama.IncrementGrade();
		Obama.IncrementGrade();
	} catch (const::Bureaucrat::GradeTooHighException &exc) // pass by reference so its not copied
	{
		std::cerr << "Increment caught exception: " << exc.what() << std::endl;
	} catch (const::Bureaucrat::GradeTooLowException &exc) // pass by reference so its not copied
	{
		std::cerr << "Increment caught exception: " << exc.what() << std::endl;
	}
	std::cout << &Obama << std::endl;
	Obama.signForm(law_proposal);
	law_proposal.beSigned(Obama);
	Obama.signForm(law_proposal);

	std::cout << &law_proposal << std::endl;
}
