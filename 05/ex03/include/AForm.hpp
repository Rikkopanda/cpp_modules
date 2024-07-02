
#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
	protected:
		const std::string 	name;
		const int			grade_sign;
		const int			grade_to_excecute;
		bool				signed_status;
	public:
		AForm(void);
		AForm(std::string _name, int grade_to_sign, int grade_to_execute, int signed_status);
		AForm(const AForm &src);
		AForm& operator=(AForm &src);
		virtual ~AForm(void);
		std::string	getName() const;
		bool	getStatus() const;
		void	beSigned(Bureaucrat &bureaucrat);
		int		getGradeToSign() const;
		int		getGradeToExcecute() const;
		virtual void 		execute(Bureaucrat const & executor) const = 0;
		void 				execute_poly(Bureaucrat const &bureaucrat, AForm const *form) const;
		virtual const std::string	getTarget(void) const;
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
		class FormIsNotToBeSignedException : public std::exception
		{
			private:
				std::string message;
			public:
				FormIsNotToBeSignedException(const char *msg);
				const char *what() const noexcept(true) override;
		};
};

std::ostream& operator<<(std::ostream &out, AForm *form);

#endif