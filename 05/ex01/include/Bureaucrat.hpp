/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/07/01 17:49:37 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {
	private:
		const std::string 	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string _name, int _grade);
		~Bureaucrat(void);
		void		initGrade(int &_grade);
		std::string	getName() const;
		int			getGrade() const;
		void		DecrementGrade();
		void		IncrementGrade();
		void		signForm(Form *form) const;
		class GradeTooHighException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException(const char *msg);
				const char *what() const noexcept(true) override;
				// ~GradeTooHighException(void);
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooLowException(const char *msg);
				const char *what() const noexcept(true) override;
				// ~GradeTooLowException(void);
		};
};

std::ostream& operator<<(std::ostream &out, Bureaucrat *bureaucrat);

#endif