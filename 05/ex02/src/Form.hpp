
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
	public:
		AForm(void);
		virtual ~AForm(void);
		virtual std::string	getName() const = 0;
		virtual bool	getStatus() const = 0;
		virtual void	beSigned(Bureaucrat &bureaucrat) = 0;
		virtual int		getGradeToSign() const = 0;
		virtual int		getGradeToExcecute() const = 0;
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
};

std::ostream& operator<<(std::ostream &out, AForm *form);



#endif