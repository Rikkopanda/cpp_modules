#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contacts.hpp"

int	main(void)
{
	std::string 			input;
	PhoneBook 	boek;

	while (1)
	{
		std::cout << "enter command:" << std::endl;
		std::cin >> input;
		if (input.compare("") == 0 || std::cin.eof())
			break;
		if (input.compare("ADD") == 0)
		{
			if (boek.add() == -1)
				return (-1);
		}
		if (input.compare("SEARCH") == 0)
		{
			if (boek.search() == -1)
				return (-1);
		}
		else if (input.compare("EXIT") == 0)
			break;
	}
	return 0;
}
