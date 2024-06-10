/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/09 09:19:33 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	private:
		const std::string 	name;
		int					grade;
	public:
		Bureaucrat(): name("Default name"), grade(1)
		{
			std::cout << "Bureaucrat "<< name << " has been constructed with grade: " << grade << std::endl;
		};
		Bureaucrat(std::string _name, int _grade): name(_name), grade(_grade)
		{
			std::cout << "Bureaucrat "<< name << " has been constructed with grade: " << grade << std::endl;
		};
		~Bureaucrat(void)
		{
			std::cout << "Bureaucrat " << name << " with grade: " << grade << " has been destructed" << std::endl;
		};
		std::string getName()
		{
			return this->name;
		};
		int getGrade()
		{
			return this->grade;
		};
		class GradeTooHighException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException(const char *msg) : message(msg)
				{
					exception::what();
				}
				const char *what()
				{
					return message.c_str();
				}
				// ~GradeTooHighException(void);
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooLowException(const char *msg) : message(msg)
				{
					what();
				}
				// ~GradeTooLowException(void);
				const char *what()
				{
					return message.c_str();
				}
		};
		void DecrementGrade()
		{
			if (grade == 150)
				throw GradeTooLowException("grade too low(1 being high and 150 low....)");
			else
				this->grade++;
		}
		void IncrementGrade()
		{
			if (grade == 1)
				throw GradeTooHighException("grade too high(1 being high and 150 low....)");
			else
				this->grade++;
		}
};

#endif