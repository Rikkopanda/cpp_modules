/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/18 12:41:22 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default name"), grade(1)
{
	std::cout << "Bureaucrat "<< name << " has been constructed with grade: " << grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name)
{
	try {
		initGrade(_grade);
	} catch (const::Bureaucrat::GradeTooHighException &exc){
		this->grade = 1;
		std::cerr << "caught exception: " << exc.what() << std::endl;
	} catch (const::Bureaucrat::GradeTooLowException &exc){
		this->grade = 150;
		std::cerr << "caught exception: " << exc.what() << std::endl;
	}
	std::cout << "Bureaucrat "<< name << " has been constructed with grade: " << grade << std::endl;
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

std::string Bureaucrat::getName()
{
	return this->name;
}

int Bureaucrat::getGrade()
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

void Bureaucrat::DecrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException("grade too low(1 being high and 150 low....)"); // runtime looks for nearest catch block in call stack
	else
		this->grade++;
}

void Bureaucrat::IncrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException("grade too high(1 being high and 150 low....)");
	else
		this->grade--;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat *bureaucrat)
{
	std::cout << bureaucrat->getName() << " bureaucrat grade " << bureaucrat->getGrade() << std::flush;
	return out;
}
