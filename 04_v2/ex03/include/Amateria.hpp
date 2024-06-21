/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:57:49 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include <cstdio>
# include "ICharacter.hpp"

# define RESET "\033[0m"
# define Black "\033[0;30m"
# define Red "\033[0;31m"
# define Green "\033[0;32m"
# define Yellow "\033[0;33m"
# define Blue "\033[0;34m"
# define Purple "\033[0;35m"
# define Cyan "\033[0;36m"
# define White "\033[0;37m"
 
# define LIGHT_GRAY "\033[37m"
# define DARK_GRAY "\033[90m"
# define BRIGHT_RED "\033[91m"
# define BRIGHT_GREEN "\033[92m"
# define BRIGHT_YELLOW "\033[93m"
# define BRIGHT_BLUE "\033[94m"
# define BRIGHT_MAGENTA "\033[95m"
# define BRIGHT_CYAN "\033[96m"

# ifndef PRINT_ALL
#  define PRINT_ALL 0
# endif

# define TRUE 1
# define FALSE 0

class ICharacter;

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria &copy);
		AMateria& operator=(const AMateria &src);
		virtual ~AMateria();
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target) = 0;
};

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string const & type);
		Ice(Ice &copy);
		Ice& operator=(const Ice &src);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target) override;
};

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string const & type);
		Cure(Cure &copy);
		Cure& operator=(const Cure &src);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target) override;
};

#endif
