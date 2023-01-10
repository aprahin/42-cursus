/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:57:01 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/29 21:57:01 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	prod1 = Point::cross_product_pos(a, point, a, b);
	bool	prod2 = Point::cross_product_pos(b, point, b, c);
	bool	prod3 = Point::cross_product_pos(c, point, c, a);

	return ((prod1 == prod2 && prod2 == prod3));
}