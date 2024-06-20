/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:37:40 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/20 10:59:12 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): name("default name"), grade_sign(145), grade_to_excecute(137), signed_status(false)
{
	std::cout << "default constructor ShrubberyCreationForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name) : name(_name), grade_sign(145),
grade_to_excecute(137), signed_status(false)
{
	std::cout << "parameter constructor ShrubberyCreationForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cerr << "ShrubberyCreationForm has been destructed" << std::endl;
}

std::string	ShrubberyCreationForm::getName() const
{
	return this->name;
}

bool	ShrubberyCreationForm::getStatus() const
{
	return this->signed_status;
}

int		ShrubberyCreationForm::getGradeToSign() const
{
	return this->grade_sign;
}

int		ShrubberyCreationForm::getGradeToExcecute() const
{
	return this->grade_to_excecute;
}

void		ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	(void)bureaucrat;
	std::cerr << "ShrubberyCreationForm excecuting.... " << std::endl;
	execute_poly(bureaucrat, this);

	std::String 

	std::ofstream NewFile(this->name + "_shrubbery");
	NewFile << "ascii tree";
	NewFile.close();
}

/**
 * if a form is already signed, nothing changes in the program's flow
 */
void	ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat)
{
	try{
		if (bureaucrat.getGrade() > this->grade_sign)
			throw GradeTooLowException("tried to sign, but bureaucrat's grade is 'lower' than grade_to_sign");
		else if (bureaucrat.getGrade() > this->grade_to_excecute)
			throw GradeTooLowException("tried to sign, but bureaucrat's grade is 'lower' than grade_to_excecute");
		this->signed_status = true;
		std::cerr << "bill has been signed by " << bureaucrat.getName() << std::endl;
	} catch (GradeTooHighException &exc)
	{
		std::cerr << "caught exception: " << exc.what() << std::endl;
	} catch (GradeTooLowException &exc)
	{
		std::cerr << "caught exception: " << exc.what() << std::endl;
	}
}
std::ostream& operator<<(std::ostream &out, AForm *form)
{
	std::cout << "Form: " << form->getName() << " sign status: " << form->getStatus() << " grade to excecute: " 
	<< form->getGradeToExcecute() << " grade to sign: " << form->getGradeToSign() << std::flush;
	return out;
}
