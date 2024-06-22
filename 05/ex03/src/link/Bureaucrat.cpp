/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/22 12:09:38 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("Default name"), grade(1)
{
	std::cout << "Bureaucrat "<< name << " has been default constructed with grade: " << grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name)
{
	try {
		initGrade(_grade);
	} catch (const::Bureaucrat::GradeTooHighException &exc){
		this->grade = 1;
		std::cout << "caught exception: " << exc.what() << std::endl;
	} catch (const::Bureaucrat::GradeTooLowException &exc){
		this->grade = 150;
		std::cout << "caught exception: " << exc.what() << std::endl;
	}
	std::cout << "Bureaucrat "<< name << " has been parameterized constructed with grade: " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.getName()), grade(src.getGrade())
{
	std::cout << "Bureaucrat " << name << " has been copy constructed with grade: "<< grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &src)
{
	this->grade = src.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << name << " with grade: " << grade << " has been destructed" << std::endl;
}

void Bureaucrat::initGrade(int &_grade)
{
	if (_grade > 150)
		throw GradeTooLowException("Tried to initialize it too low, it will now be set to 150 ");
	else if (_grade < 1)
		throw GradeTooHighException("Tried to initialize it too high, it will now be set to 1 ");
	else
		this->grade = _grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) : message(msg)
{
	std::cout << "GradeTooHighException object made with parameter constructor" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return message.c_str();
}
// ~GradeTooHighException(void);

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) : message(msg)
{
	std::cout << "GradeTooLowException object made with parameter constructor" << std::endl;
}

// ~GradeTooLowException(void);
const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return message.c_str();
} //noexcept means the function does not throw any exceptions

// void Bureaucrat::AttemptDecrement()
// {
// 	if (grade == 150)
// 		throw GradeTooLowException("grade too 'low'(1 being high and 150 low....)"); // runtime looks for nearest catch block in call stack
// 	else
// 		this->grade++;
// }

void Bureaucrat::DecrementGrade()
{
	// try {
	// 	AttemptDecrement();
	// } catch (const::Bureaucrat::GradeTooHighException &exc)
	// {
	// 	std::cout << "Increment caught exception: " << exc.what() << std::endl;
	// } catch (const::Bureaucrat::GradeTooLowException &exc)
	// {
	// 	std::cout << "Increment caught exception: " << exc.what() << std::endl;
	// }
	if (grade == 150)
		throw GradeTooLowException("grade too 'low'(1 being high and 150 low....)"); // runtime looks for nearest catch block in call stack
	else
		this->grade++;
}
// void Bureaucrat::AttemptIncrement()
// {
// 	if (grade == 1)
// 		throw GradeTooLowException("grade too 'low'(1 being high and 150 low....)"); // runtime looks for nearest catch block in call stack
// 	else
// 		this->grade--;
// }

void Bureaucrat::IncrementGrade()
{
	// try {
	// 	AttemptIncrement();
	// } catch (const::Bureaucrat::GradeTooHighException &exc)
	// {
	// 	std::cout << "Increment caught exception: " << exc.what() << std::endl;
	// } catch (const::Bureaucrat::GradeTooLowException &exc)
	// {
	// 	std::cout << "Increment caught exception: " << exc.what() << std::endl;
	// }
	if (grade == 1)
		throw GradeTooHighException("grade too 'high'(1 being high and 150 low....)");
	else
		this->grade--;
}

void Bureaucrat::signForm(AForm *form) const
{
	if (form->getStatus() == true)
		std::cout << "Form " << form->getName() << " was already signed " << std::endl;
	if (this->grade > form->getGradeToSign())
	{
		std::cout << this->name << " couldn't sign " << form->getName() << " because grade(" << this->grade << ") is 'lower' than form's grade_to_sign(" << form->getGradeToSign() << ")" << std::endl;
	}
	if (this->grade > form->getGradeToExcecute())
	{
		std::cout << this->name << " couldn't sign " << form->getName() << " because grade(" << this->grade << ") is 'lower' than form's grade_to_excecute(" << form->getGradeToExcecute() << ")" << std::endl;
	}
	else if (this->grade < form->getGradeToExcecute() && this->grade < form->getGradeToSign())
		std::cout << this->name << " could have signed " << form->getName() << " because grade(" << this->grade << ") is 'high' enough" << std::endl;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat *bureaucrat)
{
	std::cout << bureaucrat->getName() << " bureaucrat grade " << bureaucrat->getGrade() << std::flush;
	return out;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	std::cout << "Bureaucrat " << this->name << " is trying to execute " << form.getName() << std::endl;
	form.execute_poly((const Bureaucrat)*this, &form);
	std::cout << "Bureaucrat " << this->name << " executed " << form.getName() << std::endl;
}
