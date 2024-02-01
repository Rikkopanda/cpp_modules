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
		int input_data(int i);
		std::string get_name();
		void set_fields_null();
		void print_preview(int contact_nbr);
		void print_all_data();
};

void print_field(std::string str);


// helper functions

void insert_str_in_array(std::string *insert_str, std::string *str, int start, int end, int trunc);
int is_all_num(std::string str);
int is_all_spaces(std::string str);

#endif