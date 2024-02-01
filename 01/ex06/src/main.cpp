/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/01 16:31:15 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>


void set_level(std::string user_input, const std::string level_arr[4], int *level_case)
{
	*level_case = -1;

	for (int i = 0; i < 4; i++)
	{
		if (user_input.compare(0, user_input.length(), level_arr[i]) == 0)
		{
			*level_case = i;
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	Harl				h;
	std::string 		user_input;
	const std::string 	level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					level_case;

	if (argc != 2)
		return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 1);

	user_input = argv[1];

	set_level(user_input, level_arr, &level_case);

	switch (level_case)
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			h.complain("DEBUG");
			[[fallthrough]];
		case 1:
			h.complain("INFO");
			[[fallthrough]];
			break;
		case 2:
			h.complain("WARNING");
			[[fallthrough]];
			break;
		case 3:
			h.complain("ERROR");
			break;
	}
	return 0;
}