/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/08/04 14:07:13 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include "Swap.hpp"
#include "min_max.hpp"
#include <iostream>
#include "text_colors.hpp"

int main()
{
	{
		int *x = (int *)malloc(sizeof(int) * 4);
		x[0] = 0;
		x[1] = 1;
		x[2] = 2;
		x[3] = 3;
		std::cout << WHITE << "iter(&x, 4, inc)" << std::endl;
		std::cout << DARKGREY;
		iter(x, 4, print);
		iter(x, 4, incr);
		std::cout << "-----------" << std::endl;
		iter(x, 4, print);
		std::cout << WHITE << "iter(&x, 4, swap)" <<std::endl;
		std::cout << MAGENTA;
		iter(x, 4, print);
		iter(x, 4, swap);
		std::cout << "-----------" << std::endl;
		iter(x, 4, print);
		std::cout << RESET;
		free(x);
	}
}