
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class GradeTooHighException;

class Form {
	private:
		const std::string name;
		const int	grade_sign;
		const int	grade_to_excecute;
		bool		signed_status;
	public:
		Form(void);
		Form(std::string _name, int _grade_sign, int _grade_to_excecute);
		~Form(void);
		std::string	getName() const;
		bool	getStatus() const;
		void	beSigned(Bureaucrat &bureaucrat);
		int		getGradeToSign() const;
		int		getGradeToExcecute() const;
		class GradeTooHighException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException(const char *msg);
				const char *what() const noexcept(true) override;
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooLowException(const char *msg);
				const char *what() const noexcept(true) override;
		};
};

std::ostream& operator<<(std::ostream &out, Form *form);


#endif