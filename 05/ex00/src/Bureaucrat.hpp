/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/18 12:11:37 by rikverhoeve      ###   ########.fr       */
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
		Bureaucrat();
		Bureaucrat(std::string _name, int _grade);
		~Bureaucrat(void);
		void		initGrade(int &_grade);
		std::string	getName();
		int			getGrade();
		void		DecrementGrade();
		void		IncrementGrade();
		class GradeTooHighException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException(const char *msg);
				const char *what() const noexcept override;
				// ~GradeTooHighException(void);
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooLowException(const char *msg);
				const char *what() const noexcept override;
				// ~GradeTooLowException(void);
		};
};

std::ostream& operator<<(std::ostream &out, Bureaucrat *bureaucrat);

#endif