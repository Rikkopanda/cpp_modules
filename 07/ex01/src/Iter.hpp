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

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T> void incr(T *element)
{
	*element = *element + static_cast<T>(1);
}

template <typename T> void print(T *element)
{
	std::cout << *element << std::endl;
}

template <typename T> void iter (T *arr, int len, void ( *pfunction ) (T *element))
{
	for (int i = 0; i < len; i++)
	{
		pfunction(&arr[i]);
	}
}

#define OFFSET_REACH 1

template <typename T> void iter (T *arr, int len, void ( *pfunction ) (T *a, T *b))
{
	for (int i = 0; i < len - OFFSET_REACH; i++)
	{
		pfunction(&arr[i], &arr[i + 1]);
	}
}


//https://stackoverflow.com/questions/38043442/how-do-inline-variables-work

#endif
