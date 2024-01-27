#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <string>

#include "contacts.hpp"
// #include "phone_book.cpp"
// #include "helper_functions.cpp"

class PhoneBook {
	private:
		Contact pub_contacts[8];
	public:
		void add();
		void search();
		PhoneBook();
		~PhoneBook();
};

#endif