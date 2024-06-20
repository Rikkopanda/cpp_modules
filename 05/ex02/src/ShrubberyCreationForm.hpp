
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		const std::string 	name;
		const int			grade_sign;
		const int			grade_to_excecute;
		bool				signed_status;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string _name);
		~ShrubberyCreationForm(void);
		std::string	getName() const override;

		bool	getStatus() const override;
		void	beSigned(Bureaucrat &bureaucrat) override;
		int		getGradeToSign() const override;
		int		getGradeToExcecute() const override;
		void	execute(Bureaucrat const & executor) const override;
};

#endif
