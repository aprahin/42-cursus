/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:09:09 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 09:51:42 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include "colours.hpp"
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed	&operator=(const Fixed &other);
		~Fixed(void);
		Fixed(int n);
		Fixed(float f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void)	const;
	private:
		int			_number;
		static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &other);

#endif