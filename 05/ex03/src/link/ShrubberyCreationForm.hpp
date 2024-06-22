
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		const std::string 	target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm &src);
		~ShrubberyCreationForm(void);
		const std::string getTarget(void) const;
		void	execute(Bureaucrat const & executor) const override;
};

#endif
