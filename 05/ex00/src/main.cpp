/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/07/02 11:27:08 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

/*
voorbeeld om parameter te gebruiken in noexcept

void log(const std::string &msg) noexcept(Bureaucrat.IncrementGrade()) {
	std::cout << msg << std::endl;
	Trump.IncrementGrade();
}
*/

int main(void)
{
	Bureaucrat Obama("Obama", -12);
	try
	{
		Obama.IncrementGrade();
	} catch (const::Bureaucrat::GradeTooHighException &exc) // pass by reference so its not copied
	{
		std::cout << "caught exception: " << exc.what() << std::endl;
	}
	std::cout << &Obama << std::endl;

	Bureaucrat Trump("Trump", 2);

	try
	{
		Trump.IncrementGrade();
		Trump.IncrementGrade();
		Trump.IncrementGrade();
		Trump.IncrementGrade();
	} catch (const::Bureaucrat::GradeTooHighException &exc) // pass by reference so its not copied
	{
		std::cout << "caught exception: " << exc.what() << std::endl;
	}

	try
	{
		for (int i = 0; i < 200; i++)
			Trump.DecrementGrade();
	} catch (const::Bureaucrat::GradeTooHighException &exc) // pass by reference so its not copied
	{
		std::cout << "caught exception: " << exc.what() << std::endl;
	} catch (const::Bureaucrat::GradeTooLowException &exc) // pass by reference so its not copied
	{
		std::cout << "caught exception: " << exc.what() << std::endl;
	}
	std::cout << &Trump << std::endl;


}
