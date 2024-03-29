/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:18:39 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/29 10:18:40 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
