/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:37:40 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/22 10:49:36 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("default name", 72, 45, false), target("default target place")
{
	std::cout << "default constructor RobotomyRequestForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << "at target" << target <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("default name", 72, 45, false), target(_target)
{
	std::cout << "parameter constructor RobotomyRequestForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << "at target" << target <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), target(src.getTarget())
{
	std::cout << "copy constructed " <<  this->name <<  ", a RobotomyRequestForm" << std::endl;
}

/*
	can only copy signed_status, because this is not a const
*/
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
	this->signed_status = src.getStatus();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << this->name << " RobotomyRequestForm for " <<  this->target << " has been destructed" << std::endl;
}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return this->target;
}

void		RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	std::cout << "RobotomyRequestForm excecuting.... " << std::endl;
	
	
	execute_poly(bureaucrat, this);

	std::cout << "BRBRBRBBRRRRRRR DRILLING NOISES " << std::endl;
	std::cout << "BRBRBRBBRRRRRRR MORE DRILLING NOISES " << std::endl;
	std::cout << this->target << " has been robotomized succesfully 50%% of the time " << std::endl;

	// inform that robotomising has failed in case it fails

}

