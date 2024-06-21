/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:11 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:56:57 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(Fixed &src)
{
	std::cout << "Copy constructor operator called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed& Fixed::operator=(Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		value = src.getRawBits();
	return *this;
}
/*
about self-assignment:
___________________________________
void userCode(Fred& x)
{
  x = x;           // Self-assignment
}

void userCode(Fred& x, Fred& y)
{
  x = y;           // Could be self-assignment if &x == &y
}

Fred& operator= (const Fred& f)
{
	// Bad code: Doesn't handle self-assignment!
	delete p_;                // Line #1
	p_ = new Wilma(*f.p_);    // Line #2
	return *this;
}

&f could be the same as &p_(meaning *this)
so deleting p_ deletes f also.
self assignment is mistake if unaware
___________________________________
example gracefully handling it:

Fred& Fred::operator= (const Fred& f)
{
	if (this == &f) return *this;   // Gracefully handle self assignment
	// Put the normal assignment duties here...
	return *this;
}
*/
