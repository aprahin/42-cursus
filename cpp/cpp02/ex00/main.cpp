/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:07:07 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/29 18:07:07 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include <iostream>
#include "Fixed.hpp"

void	ftLog(std::string log);

int	main(void)
{
	ftLog("Initializing a Fixed instance with default constructor...");

	Fixed	a;

	ftLog("Setting its value to 42 with setRawBits...");

	a.setRawBits(42);

	ftLog("Initializing another Fixed instance using the copy constructor, copying \
the previous instance...");

	Fixed	b(a);

	ftLog("Initializing a third Fixed instance and assigning it to our last instance...");

	Fixed	c;
	c = b;

	ftLog("Calling getRawBits on every instance...");
	a.getRawBits();
	b.getRawBits();
	c.getRawBits();

	ftLog("Time to return...");

	return (0);
}