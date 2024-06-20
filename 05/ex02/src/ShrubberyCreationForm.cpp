/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:37:40 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/06/20 13:01:11 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("default name", 145, 137, false)
{
	std::cout << "default constructor ShrubberyCreationForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name) : AForm(_name, 145, 137, false)
{
	std::cout << "parameter constructor ShrubberyCreationForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	std::cerr << "copy constructed " <<  this->name <<  ", a ShrubberyCreationForm" << std::endl;
}

/*
	can only copy signed_status, because this is not a const
*/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &src)
{
	this->signed_status = src.getStatus();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cerr << this->name << " ShrubberyCreationForm " <<  this->name <<  " has been destructed" << std::endl;
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
	std::cerr << "ShrubberyCreationForm excecuting.... " << std::endl;
	execute_poly(bureaucrat, this);

	std::string small_ascii_tree = R"(       _-_
						/~~   ~~\
					/~~         ~~\
					{               }
					\  _-     -_  /
					~  \\ //  ~
					_- -   | | _- _
					_ -  | |   -_
						// \\)";
	// std::ifstream myfile;

	std::string big_ascii_tree = R"(
				.        +          .      .          .
		.            _        .                    .
	,              /;-._,-.____        ,-----.__
	((        .    (_:#::_.:::. `-._   /:, /-._, `._,
	`                 \   _|`"=:_::.`.);  \ __/ /
						,    `./  \:. `.   )==-'  .
		.      ., ,-=-.  ,\, +#./`   \:.  / /           .
	.           \/:/`-' , ,\ '` ` `   ): , /_  -o
		.    /:+- - + +- : :- + + -:'  /(o-) \)     .
	.      ,=':  \    ` `/` ' , , ,:' `'--".--"---._/`7
	`.   (    \: \,-._` ` + '\, ,"   _,--._,---":.__/
				\:  `  X` _| _,\/'   .-'
	.               ":._:`\____  /:'  /      .           .
						\::.  :\/:'  /              +
	.                 `.:.  /:'  }      .
			.           ):_(:;   \           .
						/:. _/ ,  |
					. (|::.     ,`                  .
		.                |::.    {\
						|::.\  \ `.
						|:::(\    |
				O       |:::/{ }  |                  (o
				)  ___/#\::`/ (O "==._____   O, (O  /`
			~~~w/w~"~~,\` `:/,-(~`"~~~~~~~~"~o~\~/~w|/~
	dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\|/~~
	)";

	std::ofstream NewFile(this->name + "_shrubbery");
	NewFile << small_ascii_tree + "\n" + big_ascii_tree;
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
