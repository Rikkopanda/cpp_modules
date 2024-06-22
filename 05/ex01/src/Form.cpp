/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:37:40 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/22 12:09:38 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(void): name("default name"), grade_sign(100), grade_to_excecute(120), signed_status(false)
{
	std::cout << "default constructor Form, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << std::endl;
}

Form::Form(std::string _name, int _grade_sign, int _grade_to_excecute) : name(_name), grade_sign(_grade_sign),
grade_to_excecute(_grade_to_excecute), signed_status(false)
{
	std::cout << "parameter constructor Form, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form has been destructed" << std::endl;
}

std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getStatus() const
{
	return this->signed_status;
}

int		Form::getGradeToSign() const
{
	return this->grade_sign;
}

int		Form::getGradeToExcecute() const
{
	return this->grade_to_excecute;
}

/**
 * if a form is already signed, nothing changes in the program's flow
 */
void	Form::beSigned(Bureaucrat &bureaucrat)
{
	try{
		if (bureaucrat.getGrade() > this->grade_sign || bureaucrat.getGrade() > this->grade_to_excecute)
			throw GradeTooLowException("tried to sign, but bureaucrat's grade is 'lower' than grade_to_sign");
		this->signed_status = true;
		std::cout << "bill has been signed by " << bureaucrat.getName() << std::endl;
	} catch (GradeTooHighException &exc)
	{
		std::cout << "caught exception: " << exc.what() << std::endl;
	} catch (GradeTooLowException &exc)
	{
		std::cout << "caught exception: " << exc.what() << std::endl;
	}
}

Form::GradeTooHighException::GradeTooHighException(const char *msg) : message(msg)
{
	std::cout << "GradeTooHighException object made with parameter constructor" << std::endl;
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return message.c_str();
}
// ~GradeTooHighException(void);

Form::GradeTooLowException::GradeTooLowException(const char *msg) : message(msg)
{
	std::cout << "GradeTooLowException object made with parameter constructor" << std::endl;
}

// ~GradeTooLowException(void);
const char *Form::GradeTooLowException::what() const noexcept
{
	return message.c_str();
} //noexcept means the function does not throw any exceptions

std::ostream& operator<<(std::ostream &out, Form *form)
{
	std::cout << "Form: " << form->getName() << " sign status: " << form->getStatus() << " grade to excecute: " 
	<< form->getGradeToExcecute() << " grade to sign: " << form->getGradeToSign() << std::flush;
	return out;
}
