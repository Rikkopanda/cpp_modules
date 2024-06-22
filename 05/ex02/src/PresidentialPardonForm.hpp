
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class AForm;

class PresidentialPardonForm : public AForm {
	private:
		const std::string 	target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm& operator=(PresidentialPardonForm &src);
		~PresidentialPardonForm(void);
		const std::string getTarget(void) const;
		void	execute(Bureaucrat const & executor) const override;
};

#endif
