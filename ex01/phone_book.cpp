
#include "phone_book.hpp"

void PhoneBook::search()
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
		if (input.length() > 1)
		{
			std::cout << "wrong input, supply single digit between 1 and 8";
			continue;
		}
		selected_contact = std::stoi(input);
		break;
	}
	pub_contacts[selected_contact - 1].print_all_data();
}

PhoneBook::PhoneBook()
{
	std::cout << "opening phone book\n";
}

PhoneBook::~PhoneBook()
{
	std::cout << "closing phone book\n";
}

void PhoneBook::add()
{
	int i;

	for (i = 0; i < 2; i++)
	{
		if (!pub_contacts[i].added)
			break;
	}
	pub_contacts[i].input_data(i);
	// if (pub_contacts[i].added == 0)
	// 	pub_contacts[i].set_fields_null();
}