/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/27 10:02:45 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Data_HPP
# define Data_HPP

#include <iostream>
#include <string>
#include <exception>

class Data {
	private:
		int some_data;
		//bit fields
		unsigned int a : 3; //three bits values: 0....7
		unsigned int b : 3;
		unsigned int c : 3;
		unsigned int d : 3;
	public:
		Data(void);
		Data(int data_input);
		Data(Data &src);
		int getData(void);
		~Data(void);
		Data& operator=(Data &src);
};

#endif