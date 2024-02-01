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