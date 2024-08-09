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

#ifndef Swap_HPP
# define Swap_HPP

template <typename T> void swap (T *a, T *b)
{
	T temp_val;

	temp_val = *a;
	*a = *b;
	*b = temp_val;
}

template <typename T> void swap (T &a, T &b)
{
	T temp_val = a;

	a = b;
	b = temp_val;
}


//https://stackoverflow.com/questions/38043442/how-do-inline-variables-work

#endif
