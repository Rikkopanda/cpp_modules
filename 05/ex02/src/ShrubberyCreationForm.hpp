
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		const std::string 	target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string _name);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm &src);
		~ShrubberyCreationForm(void);
		std::string	getName() const override;

		bool	getStatus() const override;
		void	beSigned(Bureaucrat &bureaucrat) override;
		int		getGradeToSign() const override;
		int		getGradeToExcecute() const override;
		void	execute(Bureaucrat const & executor) const override;
};

#endif
