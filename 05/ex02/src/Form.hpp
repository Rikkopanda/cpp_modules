
#ifndef FORM_HPP
# define FORM_HPP

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
		AForm(std::string _name, int grade_to_sign, int signed_status, int grade_to_execute);
		AForm(const AForm &src);
		AForm& operator=(AForm &src);
		virtual ~AForm(void);
		virtual std::string	getName() const;
		virtual bool	getStatus() const;
		virtual void	beSigned(Bureaucrat &bureaucrat);
		virtual int		getGradeToSign() const;
		virtual int		getGradeToExcecute() const;
		virtual void 	execute(Bureaucrat const & executor) const = 0;
		void 			execute_poly(Bureaucrat const &bureaucrat, AForm const *form) const;
		class GradeTooHighException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException(const char *msg);
				const char *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooLowException(const char *msg);
				const char *what() const noexcept override;
		};
		class FormIsNotToBeSignedException : public std::exception
		{
			private:
				std::string message;
			public:
				FormIsNotToBeSignedException(const char *msg);
				const char *what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream &out, AForm *form);

#endif