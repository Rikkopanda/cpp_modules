/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts_helper_functions.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:14:42 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/27 11:35:02 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

void insert_str_in_array(std::string *insert_str, std::string *str, int start, int end, int trunc)
{
	int i;
	int j;

	j = 0;
	for (i = 0; i <= end; i++)
	{
		if (start <= i && j <= (int)(*str).length())
			(*str)[i] = (*insert_str)[j++];
	}
	if (trunc)
	{
		if (j < (int)(*insert_str).length())
			(*str)[end] = '.';
	}
}

int is_all_num(std::string str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!(str[i] > 47 && str[i] < 58))
			return (0);
		i++;
	}
	return (1);
}

int is_all_spaces(std::string str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!((str[i] > 8 && str[i] < 14)
		|| (str[i] == 32)))
			return (0);
		i++;
	}
	return (1);
}

//std::string truncate(std::string str, size_t width, bool show_ellipsis=true)
//{
//    if (str.length() > width)
//        if (show_ellipsis)
//            return str.substr(0, width) + ".";
//        else
//            return str.substr(0, width);
//    return str;
//}
