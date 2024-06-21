/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:24:39 by rikverhoeve       #+#    #+#             */
/*   Updated: 2024/05/08 10:47:16 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include <cstdio>
# include "Amateria.hpp"

/**
 * allocation and freeing memory is as followed:
 * 
 * it is assumed for all AMateria's passed to learnMateria(AMateria* m),
 * that materiaSource object is responsible for the
 * destructing and freeing memory of those
 * 
 * be careful!;
 * 
 * to not cause invalid freeing, do not equip a Character with a AMateria
 * who is also learned by MateriaSource
 * 
*/
class IMateriaSource
{
	protected:
		AMateria	*slots[4];
	public:
		IMateriaSource();
		IMateriaSource(const IMateriaSource &src);
		IMateriaSource& operator=(const IMateriaSource &src);
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource& operator=(const MateriaSource &src);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
