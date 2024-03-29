/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:18:54 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/29 10:18:55 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <string>

#include "Contacts.hpp"

class PhoneBook {
	private:
		Contact pub_contacts[8];
	public:
		int add();
		int search();
		PhoneBook();
		~PhoneBook();
};

#endif