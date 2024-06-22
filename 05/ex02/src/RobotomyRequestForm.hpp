
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class AForm;

class RobotomyRequestForm : public AForm {
	private:
		const std::string 	target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm& operator=(RobotomyRequestForm &src);
		~RobotomyRequestForm(void);
		const std::string getTarget(void) const;

		void	execute(Bureaucrat const & executor) const override;
};

#endif
