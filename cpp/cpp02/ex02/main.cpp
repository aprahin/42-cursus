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

void	myMain()
{
	ftLog("I'll have two numbers: 4.25 and 2");

	Fixed	a(4.25f);
	Fixed	b(2);

	ftLog("Let's compare them!");

	ftLog(">");
	std::cout << _CYAN << (a > b) << _END << std::endl;
	ftLog("<");
	std::cout << _CYAN << (a < b) << _END << std::endl;
	ftLog(">=");
	std::cout << _CYAN << (a >= b) << _END << std::endl;
	ftLog("<=");
	std::cout << _CYAN << (a <= b) << _END << std::endl;
	ftLog("==");
	std::cout << _CYAN << (a == b) << _END << std::endl;
	ftLog("!=");
	std::cout << _CYAN << (a != b) << _END << std::endl;
	
	ftLog("What about operations?");

	ftLog("+");
	std::cout << _CYAN << (a + b) << _END << std::endl;
	ftLog("-");
	std::cout << _CYAN << (a - b) << _END << std::endl;
	ftLog("*");
	std::cout << _CYAN << (a * b) << _END << std::endl;
	ftLog("/");
	std::cout << _CYAN << (a / b) << _END << std::endl;

	ftLog("Finally, some handy functions...");

	ftLog("min");
	std::cout << _CYAN << Fixed::min(a, b) << _END << std::endl;
	ftLog("max");
	std::cout << _CYAN << Fixed::max(a, b) << _END << std::endl;

	ftLog("OK I'm out");
	return ;
}

void	givenMain()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ftLog("Usage: ./fixed [ap, 42]");
		return (1);
	}
	else if (av[1] == std::string("ap"))
		myMain();
	else if (av[1] == std::string("42"))
		givenMain();
	else
		main(1, av);
	return (0);
}