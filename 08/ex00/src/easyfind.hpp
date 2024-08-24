/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikverhoeven <rikverhoeven@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/06/27 10:02:45 by rikverhoeve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <array>
#include <vector>
#include <list>
#include <iostream>



// template <typename Iterator> Iterator 	iterate (Iterator begin, Iterator end, int to_find)
// {
// 	std::find(begin, end, to_find);	
// 	return (a < b ? a : b);
// }

/**
 * finds element in T container and returns T::Iterator
 * 
 * type of iterator it returns depends on the type of container used
 * 
 * 
 */
template <typename T, typename E> 
typename T::iterator easyfind (T container, E to_find)
{
	auto ret_i = std::find(container.begin(), container.end(), to_find);

	if (ret_i == container.end())
	
	return ;
}\

template <typename T> T max (T a, T b)
{
	return (a > b ? a : b);
}

//https://stackoverflow.com/questions/38043442/how-do-inline-variables-work

#endif
