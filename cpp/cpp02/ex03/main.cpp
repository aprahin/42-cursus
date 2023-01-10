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
#include "Point.hpp"
#include <cstdlib>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	ftLog(std::string log);

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ftLog("Usage: ./bsp [x] [y]");
		return (1);
	}
	Point	p(static_cast<float>(std::atof(av[1])), static_cast<float>(std::atof(av[2])));
	Point	a(0, 0);
	Point	b(4, 4);
	Point	c(8, 0);

	std::cout << bsp(a, b, c, p) << std::endl;
	return (0);
}