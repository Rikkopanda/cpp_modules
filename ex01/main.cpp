#include <iostream>
#include <string>     // std::char_traits

void	ft_toupper(char *c)
{
	if (*c >= 97 && *c <= 122)
		*c -= 32;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
		void cancel_input();
};

void Contact::input_data(int i)
{
	std::cout << "enter first name\n";
	std::cin >> Contact::first_name;
	std::cout << "enter last name\n";
	std::cin >> Contact::last_name;
	std::cout << "enter nick name\n";
	std::cin >> Contact::nick_name;

	Contact::added = 1;
	std::cout << Contact::first_name;
	std::cout << "adding contact " << i << "\n";
}

void Contact::cancel_input()
{
	std::string first_name = NULL;
	std::string last_name = NULL;
	std::string nick_name = NULL;
	std::string phone_number = NULL;
	std::string darkest_secret = NULL;
}

Contact::Contact()
{
	Contact::added = 0;
}

class PhoneBook {
	private:
		Contact pub_contacts[8];
	public:
		void add();
		PhoneBook();
		~PhoneBook();
}boek1;

void PhoneBook::add()
{
	int i;

	for (i = 0; i < 2; i++)
	{
		if (!pub_contacts[i].added)
			break;
	}
	pub_contacts[i].input_data(i);
	if (pub_contacts[i].added == 0)
		pub_contacts[i].cancel_input();
}

PhoneBook::PhoneBook()
{
	std::cout << "opening phone book\n";
}

PhoneBook::~PhoneBook()
{
	std::cout << "closing phone book\n";
}

int	main(int argc, char *argv[])
{
	std::string input;

	while (1)
	{
		std::cout << "enter command:\n";
		std::cin >> input;
		if (input.compare("") == 0)
			break;
		if (input.compare("ADD") == 0)
			boek1.add();
		else if (input.compare("EXIT") == 0)
			break;
	}

	return 0;
}
