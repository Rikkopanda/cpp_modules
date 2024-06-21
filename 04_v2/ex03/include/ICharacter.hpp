/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:24:39 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/05/09 11:15:58 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
# include <cstdio>
# include "Amateria.hpp"

class AMateria;

class ICharacter
{
	protected:
		std::string	name;
		AMateria	*slots[4];
	public:
		ICharacter();
		ICharacter(std::string _name);
		ICharacter(ICharacter &src);
		ICharacter& operator=(const ICharacter &src);
		virtual ~ICharacter();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string _name);
		Character(Character &src);
		Character& operator=(const Character &src);
		~Character();
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
