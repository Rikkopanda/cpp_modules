#include <iostream>
#include <string>

#include "phone_book.hpp"
#include "contacts.hpp"

int	main(int argc, char *argv[])
{
	std::string 			input;
	PhoneBook 	boek;

	while (1)
	{
		std::cout << "enter command:\n";
		std::cin >> input;
		if (input.compare("") == 0)
			break;
		if (input.compare("ADD") == 0)
			boek.add();
		if (input.compare("SEARCH") == 0)
			boek.search();
		else if (input.compare("EXIT") == 0)
			break;
	}

	return 0;
}
