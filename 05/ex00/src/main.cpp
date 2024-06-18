/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/18 11:54:43 by rikverhoeve      ###   ########.fr       */
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
		std::cerr << "caught exception: " << exc.what() << std::endl;
	}
	std::cout << &Obama << std::endl;
}