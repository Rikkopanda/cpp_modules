
#include "PhoneBook.hpp"
#include "strings_f.hpp"

int PhoneBook::search()
{
	std::string input;
	int			selected_contact;

	for (int i = 0; i < 8; i++)
	{
		pub_contacts[i].print_preview(i + 1);
	}
	while (1)
	{
		std::cout << "select contact(number)\n";
		std::cin >> input;
		if (std::cin.eof())
			return (-1);
		if (input.length() > 1)
		{
			std::cout << "wrong input, supply single digit between 1 and 8";
			continue;
		}
		selected_contact = f_stoi(input);
		break;
	}
	pub_contacts[selected_contact - 1].print_all_data();
	return (0);
}
//std::cout << "ctrl-d pressed" << std::endl,

PhoneBook::PhoneBook()
{
	std::cout << "opening phone book\n";
}

PhoneBook::~PhoneBook()
{
	if (std::cin.eof())
		std::cout << std::endl;
	std::cout << "closing phone book\n";
}

int PhoneBook::add()
{
	int i;

	for (i = 0; i < 7; i++)
	{
		if (!pub_contacts[i].added)
			break;
	}
	if (i == 7)
		std::cout << "Warning: overwriting 8th contact" << std::endl;
	if (pub_contacts[i].input_data(i) == -1)
		return (-1);
	// if (pub_contacts[i].added == 0)
	// 	pub_contacts[i].set_fields_null();
	return (0);
}