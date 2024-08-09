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

#ifndef MIN_MAX_HPP
# define MIN_MAX_HPP

template <typename T> T min (T a, T b)
{
	return (a < b ? a : b);
}

template <typename T> T max (T a, T b)
{
	return (a > b ? a : b);
}

//https://stackoverflow.com/questions/38043442/how-do-inline-variables-work

#endif
