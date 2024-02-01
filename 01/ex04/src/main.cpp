/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:23:01 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/31 15:34:52 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

typedef struct s_data
{
	std::fstream	infile;
	std::fstream	outfile;
	std::string		infile_name;
	std::string		outfile_name;
	std::string		str_to_replace;
	std::string		str_replacement;
	std::string		in_str;
	std::string		str_found;
} t_data;

int file_opening(t_data *d, char *argv[])
{
	(*d).infile.open((*d).infile_name.c_str(), std::ios::in);
	if ((*d).infile.fail())
	{
		std::cout << argv[0] << ": can't open " << (*d).infile_name << std::endl;
		return -2;
	}
	(*d).outfile.open((*d).outfile_name.c_str(), std::ios::out);
	if ((*d).outfile.fail())
	{
		std::cout << argv[0] << ": can't open " << (*d).outfile_name << std::endl;
		return -2;
	}
	return 0;
}

void replacing(t_data *d)
{
	size_t	i;
	size_t	pos;
	int 	len;

	i = 0;
	while (!(*d).infile.eof())
	{
		std::getline((*d).infile, (*d).in_str);
		if (!(*d).infile.eof())
			(*d).in_str.append("\n");
		pos = 0;
		i = 0;
		while (i < (*d).in_str.length())
		{
			pos = (*d).in_str.find((*d).str_to_replace, i);
			if (pos == std::string::npos)
			{
				//(*d).in_str.resize((*d).in_str.size() - 1);
				(*d).outfile << (*d).in_str.substr(i) << std::flush;
				break ;
			}
			len = pos - i;
			(*d).outfile << (*d).in_str.substr(i, len) << std::flush;
			(*d).outfile << (*d).str_replacement << std::flush;
			i = pos + (*d).str_to_replace.length();
		}
		//if (pos != std::string::npos && !(*d).infile.eof())
		//	(*d).outfile << std::endl;
	}
}

// ./exe filename s1 s2
int main(int argc, char *argv[])
{
	t_data data;

	if (argc != 4)
		return 1;
	data.infile_name = argv[1];
	data.outfile_name = data.infile_name + ".replace";
	data.str_to_replace = argv[2];
	data.str_replacement = argv[3];

	if (file_opening(&data, argv) == -2)
		return -2;

	replacing(&data);

	data.infile.close();
	data.outfile.close();

	return 0;
}
//std::cout << "-i = " << i << "-" << std::flush;
//std::cout << "_pos = " << pos << "_" << std::flush;
//std::cout << "-len = " << len << "-" << std::flush;
/*
k	a	a	s
o	k

a		o	k		o	k		b	y	e
0	1	2	3	4	5	6	7	8	9	10

i	= 0
pos	= 2

substr(i, pos)
str_replc

i = 2 + "ok".lenght()

*/

