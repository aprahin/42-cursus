/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:04:18 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/07 16:05:12by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include "whatever.hpp"
#include <iostream>
#include <string>

void	ftLog(std::string log);

int	main(void)
{
	int	i = 42;
	int	i2 = 30;
	test_template("integer", i, i2);

	float	f = 13.37f;
	float	f2 = -20.0f;
	test_template("float", f, f2);

	double	d = 2000.001;
	double	d2 = 0;
	test_template("double", d, d2);

	char	c = '*';
	char	c2 = '/';
	test_template("char", c, c2);

	std::string	s = "chaine1";
	std::string	s2 = "chaine2";
	test_template("string", s, s2);

	bool	b = true;
	bool	b2 = false;
	test_template("bool", b, b2);

	long long int l = 1237481274982472;
	long long int l2 = -17238947219847982;
	test_template("long long integer", l, l2);
	
	return (0);
}