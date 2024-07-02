/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:37:40 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/07/01 18:18:18 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("default name", 145, 137, false), target("default target place")
{
	std::cout << "default constructor ShrubberyCreationForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("default name", 145, 137, false), target(_target)
{
	std::cout << "parameter constructor ShrubberyCreationForm, initialize " << name << "'s grade_sign to " << grade_sign << ", grade_to_excecute to " << grade_to_excecute << "at target" << target <<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target(src.getTarget())
{
	std::cout << "copy constructed " <<  this->name <<  ", a ShrubberyCreationForm" << std::endl;
}

/*
	can only copy signed_status, because this is not a const
*/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &src)
{
	this->signed_status = src.getStatus();
	return *this;
}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << this->name << " ShrubberyCreationForm for " <<  this->target <<  " has been destructed" << std::endl;
}

void		ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	std::cout << "ShrubberyCreationForm excecuting.... " << std::endl;
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

// /**
//  * if a form is already signed, nothing changes in the program's flow
//  */
// void	ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat)
// {
// 	try{
// 		if (bureaucrat.getGrade() > this->grade_sign)
// 			throw GradeTooLowException("tried to sign, but bureaucrat's grade is 'lower' than grade_to_sign");
// 		else if (bureaucrat.getGrade() > this->grade_to_excecute)
// 			throw GradeTooLowException("tried to sign, but bureaucrat's grade is 'lower' than grade_to_excecute");
// 		this->signed_status = true;
// 		std::cout << "bill has been signed by " << bureaucrat.getName() << std::endl;
// 	} catch (GradeTooHighException &exc)
// 	{
// 		std::cout << "caught exception: " << exc.what() << std::endl;
// 	} catch (GradeTooLowException &exc)
// 	{
// 		std::cout << "caught exception: " << exc.what() << std::endl;
// 	}
// }


