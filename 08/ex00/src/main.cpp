/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rik <rik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:02:30 by rverhoev          #+#    #+#             */
/*   Updated: 2024/08/23 16:17:53 by rik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include "text_colors.hpp"
#include <stddef.h>
#include <stack>
#include <set>

int main()
{
	{
		std::array<int, 5> arr = {1, 2, 3, 4, 5};

		auto it = easyfind(arr, 12);
		auto it2 = it;
		std::cout << --it << std::endl;
		std::cout << RED << "array container" << RESET << std::endl;
		std::cout << *it << std::endl;
		std::cout << "< operator: " << (it2 > it) << std::endl;
		it--;
		it--;
		std::cout << *it << std::endl;
		it--;
		std::cout << *it << std::endl;
		std::cout << std::endl;
	}
	{
		std::list<int> lst = {1, 2, 3, 4, 5};

		auto it = easyfind(lst, 2);
		std::cout << BLUE << "list container" << RESET << std::endl;

		std::list<int>::iterator it_lst;
		for (it = lst.begin(); it != lst.end(); ++it){
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		// std::cout << *it << std::endl;
		// it++; segfault
		// it++;
		// std::cout << *it << std::endl;
		// it--;
		lst.push_back(123);
		std::cout << *it << std::endl;
	}
	{
		std::set<int> set = {1, 2, 3, 4, 5};

		auto it = easyfind(set, 2);
		std::cout << BLUE << "list container" << RESET << std::endl;

		std::list<int>::iterator it_lst;
		for (it = set.begin(); it != set.end(); ++it){
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		set.upper_bound(5);
		std::cout << *it << std::endl;
	}
	{
		std::stack<int> stack;
		std::cout << MAGENTA << "stack container" << RESET << std::endl;
		std::cout << stack.size() << std::endl;
		stack.push(3);
		stack.push(4);
		stack.push(5);
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.top() << std::endl;
		stack.push(6);
		std::cout << stack.top() << std::endl;
		std::cout << std::endl;
	}
	return 0;
}