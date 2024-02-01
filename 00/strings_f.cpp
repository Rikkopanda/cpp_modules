/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itos.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:34:10 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/29 08:40:10 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	f_stoi(std::string str)
{
	int	i;
	int	min;
	int	num;

	num = 0;
	min = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		min = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + ((char)str[i] - 48);
		i++;
	}
	return (num * min);
}

static int nbr_len(int n)
{
	size_t	i;

	i = 1;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	itos(int num, std::string str)
{
	int					digits;
	int					digits_save;

	digits = nbr_len(num);
	digits_save = digits;
	(str)[digits] = '\0';
	while (digits--)
	{
		(str)[digits] = num % 10 + '0';
		num = num / 10;
	}
	return (digits_save);
}
