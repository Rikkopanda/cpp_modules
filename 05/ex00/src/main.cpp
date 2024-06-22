/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/22 12:09:38 by rverhoev         ###   ########.fr       */
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
}