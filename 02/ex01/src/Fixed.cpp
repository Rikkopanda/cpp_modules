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

#include "../include/Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixed_point_val = 0;
}

/*
	max int to fixed point<8>
	is 2^(31 - 8) = 8388608
*/
Fixed::Fixed(const int n)
{
	_fixed_point_val = n << fract_bits;
	std::cout << "Default int to Fixed constructor called" << std::endl;
}

/*

*/
Fixed::Fixed(const float n)
{
	_fixed_point_val = std::roundf(n * (1 << fract_bits));
	std::cout << "Default float to Fixed constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor operator called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
	int	ival = (_fixed_point_val >> fract_bits);

	return (ival);
}

/*
	AND bitwise to match specific bit before fixed point

	first take the 'integer part' of the raw value

	2^-n down to 2^-1 for float in respect to 2^n down to 2^0 of the raw int
*/
float Fixed::toFloat(void) const
{
	float	fval = float(_fixed_point_val >> fract_bits);
	int		i;

	i = 0;
	while (i < fract_bits)
	{
		if (((int)pow(2, i) & _fixed_point_val) == (int)pow(2, i))
			fval += pow(2, i - fract_bits);
		i++;
	}
	return (fval);
}
//std::cout << pow(2, i - fract_bits) << std::endl;

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point_val);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point_val = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_fixed_point_val = src.getRawBits();
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
