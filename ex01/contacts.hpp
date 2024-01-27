#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <string>

// #include "contacts.cpp"
// #include "helper_functions.cpp"

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	public:
		int	added;
		Contact();
		void input_data(int i);
		std::string get_name();
		void set_fields_null();
		void print_preview(int contact_nbr);
		void print_all_data();
};

#endif