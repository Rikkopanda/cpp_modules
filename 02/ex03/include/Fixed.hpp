/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:09 by rverhoev          #+#    #+#             */
/*   Updated: 2024/02/05 13:57:49 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cstdio>
#define PRINT_BOOL 0

class Fixed {
	private:
		int               _fixed_point_val;
		const static int  fract_bits = 8;
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &src);
		Fixed(const Fixed &A, const Fixed &B);
		const Fixed& operator=(const Fixed& src);
		int		operator>(const Fixed& B);
		~Fixed();
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int 	operator>(const Fixed& A) const;
		int 	operator<(const Fixed& A) const;
		int 	operator==(const Fixed& A) const;
		int 	operator!=(const Fixed& A) const;
		int 	operator<=(const Fixed& A) const;
		int 	operator>=(const Fixed& A) const;
		Fixed   operator+( const Fixed &A ) const;
		Fixed   operator-( const Fixed &A ) const;
		Fixed   operator*( const Fixed &A ) const;
		Fixed   operator/( const Fixed &A ) const;
		Fixed	operator++(int);
		Fixed&	operator++(void);
		Fixed	operator--(int);
		Fixed&	operator--(void);
		static const	Fixed&	max(const Fixed &A, const Fixed &B);
		static const	Fixed&	min(const Fixed &A, const Fixed &B);
		static			Fixed&	max(Fixed &A, Fixed &B);
		static			Fixed&	min(Fixed &A, Fixed &B);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif