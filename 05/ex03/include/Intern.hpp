#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>

#define ROBOTOMY_REQUEST "robotomy request"
#define PRESI_PARDON_REQUEST "presidential pardon"
#define SCHRUB_REQUEST "shrubbery creation"

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

typedef AForm* (*CreateFuncsPtrs[3])(std::string target);

AForm *CreateRobotomyRequestForm(std::string target);
AForm *CreatePresidentialPardonForm(std::string target);
AForm *CreateShrubberyCreationForm(std::string target);

struct FormCreationEntry {
    const char* formTypeName;
    AForm* (*createFunc)(std::string target);
};

class Intern{
	private:
    	const FormCreationEntry formCreationTable[3] = {
			{"robotomy request", CreateRobotomyRequestForm},
			{"presidential pardon", CreatePresidentialPardonForm},
			{"shrubbery creation", CreateShrubberyCreationForm}
		};
	public:
		Intern(void);
		~Intern(void);
		AForm *makeForm(std::string form_type_name, std::string target) const;
		class Wrong_Creation_Request_Exception : public std::exception
		{
			private:
				std::string message;
			public:
				Wrong_Creation_Request_Exception(const char *msg);
				const char *what() const noexcept override;
		};
};

#endif