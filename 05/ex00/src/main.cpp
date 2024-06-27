/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/27 13:21:25 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

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
