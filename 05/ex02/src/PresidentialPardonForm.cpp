/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:37:40 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/22 10:49:36 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("default name", 25, 5, false), target("default target place")
{
	std::cout << "default constructor PresidentialPardonForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << "at target" << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("default name", 25, 5, false), target(_target)
{
	std::cout << "parameter constructor PresidentialPardonForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << "at target" << target <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), target(src.getTarget())
{
	std::cout << "copy constructed " <<  this->name <<  ", a PresidentialPardonForm" << std::endl;
}

/*
	can only copy signed_status, because this is not a const
*/
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
	this->signed_status = src.getStatus();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << this->name << " PresidentialPardonForm for " <<  this->target  <<  " has been destructed" << std::endl;
}

const std::string PresidentialPardonForm::getTarget(void) const
{
	return this->target;
}

void		PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	std::cout << "PresidentialPardonForm excecuting.... " << std::endl;
	
	execute_poly(bureaucrat, this);

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

	// inform that robotomising has failed in case it fails
}


// void	PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat)
// {
// 	AForm::beSigned(bureaucrat);
// }

