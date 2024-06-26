/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:37:40 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/22 12:34:56 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(void): name("default name"), grade_sign(1),
	grade_to_excecute(1), signed_status(false)
{
	std::cout << "AForm default constructor called, made: " << this->name << std::endl;
}

// Form::Form(std::string _name, int _grade_sign, int _grade_to_excecute) : name(_name), grade_sign(_grade_sign),
// grade_to_excecute(_grade_to_excecute), signed_status(false)
// {
// 	std::cout << "parameter constructor Form, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << std::endl;
// }

AForm::AForm(AForm const &src) : name(src.getName()), grade_sign(src.getGradeToSign()),
	grade_to_excecute(src.getGradeToExcecute()), signed_status(src.getStatus())
{
	std::cout << "AForm copy constructor called, made: " << this->name << std::endl;
}

AForm::AForm(std::string _name, int grade_to_sign, int grade_to_execute, int signed_status) : name(_name), grade_sign(grade_to_sign),
	grade_to_excecute(grade_to_execute), signed_status(signed_status)
{
	std::cout << "AForm parameter constructor called, made: " << this->name << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Form " << name << " has been destructed" << std::endl;
}


std::string	AForm::getName() const
{
	return this->name;
}

bool	AForm::getStatus() const
{
	return this->signed_status;
}

int		AForm::getGradeToSign() const
{
	return this->grade_sign;
}

int		AForm::getGradeToExcecute() const
{
	return this->grade_to_excecute;
}

/**
 * if a form is already signed, nothing changes in the program's flow
 */
void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	try{
		if (bureaucrat.getGrade() > this->grade_sign)
			throw GradeTooLowException("tried to sign, but bureaucrat's grade is 'lower' than grade_to_sign");
		else if (bureaucrat.getGrade() > this->grade_to_excecute)
			throw GradeTooLowException("tried to sign, but bureaucrat's grade is 'lower' than grade_to_excecute");
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

void		AForm::execute_poly(Bureaucrat const &bureaucrat, AForm const *form) const
{
	if (bureaucrat.getGrade() > form->getGradeToSign())
		throw GradeTooLowException("tried to execute, but bureaucrat's grade is 'lower' than grade_to_sign");
	else if (bureaucrat.getGrade() > form->getGradeToExcecute())
		throw GradeTooLowException("tried to execute, but bureaucrat's grade is 'lower' than grade_to_excecute");
	else if (this->getStatus() == false)
		throw FormIsNotToBeSignedException("tried to execute, but form's sign permission status is false");
}

AForm::GradeTooHighException::GradeTooHighException(const char *msg) : message(msg)
{
	std::cout << "GradeTooHighException object made with parameter constructor" << std::endl;
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return message.c_str();
}
// ~GradeTooHighException(void);

AForm::GradeTooLowException::GradeTooLowException(const char *msg) : message(msg)
{
	std::cout << "GradeTooLowException object made with parameter constructor" << std::endl;
}

const std::string AForm::getTarget(void) const
{
	return "AForm doesn't have target";
}

// ~GradeTooLowException(void);
const char *AForm::GradeTooLowException::what() const noexcept
{
	return message.c_str();
} //noexcept means the function does not throw any exceptions

AForm::FormIsNotToBeSignedException::FormIsNotToBeSignedException(const char *msg) : message(msg)
{
	std::cout << "FormIsNotToBeSignedException object made with parameter constructor" << std::endl;
}

// ~GradeTooLowException(void);
const char *AForm::FormIsNotToBeSignedException::what() const noexcept
{
	return message.c_str();
} //noexcept means the function does not throw any exceptions

std::ostream& operator<<(std::ostream &out, AForm *form)
{
	std::cout << "Form: " << form->getName() << " sign status: " << form->getStatus() << " grade to excecute: " 
	<< form->getGradeToExcecute() << " grade to sign: " << form->getGradeToSign() << " target: "<< form->getTarget() << std::flush;
	return out;
}
