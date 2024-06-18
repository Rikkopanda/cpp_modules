
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form {
	private:
		std::string name;
		bool		signed_status;
		const int	grade_sign;
		const int	grade_to_excecute;
	public:
		Form(std::string _name) : name(_name)
		{
			
		}
		void		initStatus(bool &_status);
		std::string	getName();
		int			getStatus();
		void		beSigned();

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


}

std::ostream& operator<<(std::ostream &out, Form *form);


#endif