/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:30:28 by rik               #+#    #+#             */
/*   Updated: 2024/01/29 10:06:35 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "stdlib.h"

void Contact::print_preview(int contact_nbr)
{
	std::string contact_nbr_str;

	std::cout << contact_nbr << std::flush;
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

void print_field(std::string str)
{
	std::string		print_str;
	int				start_i;

	print_str = "          |";
	start_i = (print_str.length() - 1)  - str.length();
	if (start_i < 0)
		start_i = 0;
	insert_str_in_array(&str, &print_str, start_i, 9, 1);
	std::cout << print_str;
}

/*
getline reads untill newline
if input is all spaces, try again.

______________
if you want to handle crtl-d to make it
request again for input(empty str) or storing (non-empty str)

#include <stdio.h>
if (std::cin.eof() && str == "")
{
	clearerr(stdin);
	std::cin.clear()
	user_input(....);
	return (0);
}
if (std::cin.eof())
{

	clearerr(stdin);
	std::cin.clear();
}
*/
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
	if (std::cin.eof())
		return (-1);
	std::cin.clear();
	if (is_all_spaces(str))
	{
		std::cout << "ERROR: fields cant be empty" << std::endl;
		std::cin.clear();	
		if (user_input(prompt_text, dest) == -1)
			return (-1);
	}
	return (0);
}
//std::cout << "ctrl-d pressed" << std::endl

int user_input_phone_number(std::string *phone_number, std::string *first_name)
{
	std::string prompt_text;

	prompt_text = "enter" + *first_name + "'s " + "phone number";
	while (1)
	{
		if (user_input(prompt_text, phone_number) == -1)
			return (-1);
		if (!(is_all_num(*phone_number) && (*phone_number).length() > 2 && (*phone_number).length() < 14))
		{
			std::cout << "ERROR: phone number can contain only digits and must be between 3 and 13 digits" << std::endl;
		}
		else
			break;
	}
	return (0);
}

int Contact::input_data(int i)
{
	std::string prompt_text;

	if (user_input("enter first name", &first_name) == -1)
		return (-1);
	prompt_text = "enter " + first_name + "'s " + "last name";
	if (user_input(prompt_text, &last_name) == -1)
		return (-1);
	prompt_text = "enter " + first_name + "'s " + "nick name";
	if (user_input(prompt_text, &nick_name) == -1)
		return (-1);
	if (user_input_phone_number(&phone_number, &first_name) == -1)
		return (-1);
	prompt_text = "enter " + first_name + "'s " + "darkest secret";
	if (user_input(prompt_text, &darkest_secret) == -1)
		return (-1);

	Contact::added = 1;
	std::cout << "succesfully added contact " << i + 1 << "/" << "8\n";
	return (0);
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
