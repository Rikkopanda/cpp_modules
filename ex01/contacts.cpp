/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rik <rik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:30:28 by rik               #+#    #+#             */
/*   Updated: 2024/01/26 18:42:34 by rik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

void print_field(std::string str)
{
	char		print_str[10];
	int 		i;
	int			start_i;
	int			trunc;
	int			display_field_len;

	trunc = 0;
	start_i = 9 - str.length();
	if (start_i < 0)
	{
		start_i = 0;
		trunc = 1;
	}
	display_field_len = 9 - trunc;
	for (i = 0; i < display_field_len; i++)
	{
		if (start_i <= i)
			print_str[i] = str[i - start_i];
		else
			print_str[i] = ' ';
	}
	if (trunc)
		print_str[i++] = '.';
	print_str[i] = '|';
	std::cout << print_str;
}

void Contact::print_preview(int contact_nbr)
{
	std::string contact_nbr_str;

	contact_nbr_str = std::to_string(contact_nbr);
	print_field(contact_nbr_str);
	print_field(Contact::first_name);
	print_field(Contact::last_name);
	print_field(Contact::nick_name);
	std::cout << std::endl;
}

void Contact::set_fields_null()
{
	first_name.clear();
	last_name.clear();
	nick_name.clear();
	phone_number.clear();
	darkest_secret.clear();
}

Contact::Contact()
{
	Contact::set_fields_null();
	Contact::added = 0;
}

int user_input(std::string prompt_text, std::string *dest)
{
	std::string str;

	str = "";
	std::cout << prompt_text << std::endl;
	while (!std::cin.eof() && str == "")
	{
		if (std::getline(std::cin, str) && str != "")
			*dest = str;
		if (str != "")
			break;
	}
	std::cin.clear();
	return (0);
}

void Contact::input_data(int i)
{
	std::string prompt_text;

	if (user_input("enter first name", &first_name) == -1)
		return;
	prompt_text = "enter" + first_name + "'s " + "last name";
	user_input(prompt_text, &last_name);
	prompt_text = "enter" + first_name + "'s " + "nick name";
	user_input(prompt_text, &nick_name);
	prompt_text = "enter" + first_name + "'s " + "phone number";
	user_input(prompt_text, &phone_number);
	prompt_text = "enter" + first_name + "'s " + "darkest secret";
	user_input(prompt_text, &darkest_secret);

	Contact::added = 1;
	std::cout << Contact::first_name;
	std::cout << first_name << "succesfully added contact " << i + 1 << "/" << "8\n";
}
// check if field is empty still, maybe char array

void Contact::print_all_data()
{
	std::cout << "first_name: " << first_name << "\n";
	std::cout << "last_name: " << last_name << "\n";
	std::cout << "nick_name: " << nick_name << "\n";
	std::cout << "phone_number: " << phone_number << "\n";
	std::cout << "darkest_secret: " << darkest_secret << "\n";
}

std::string Contact::get_name()
{
	return (first_name);
}
