/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:39:57 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/29 21:39:57 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(const Fixed a, const Fixed b);
		Point(const Point &other);
		Point	&operator=(const Point &other);
		~Point(void);
		
		static bool	cross_product_pos(
			const Point &a,
			const Point &b,
			const Point &s,
			const Point &t);
	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif