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
#include "iter.hpp"
#include <iostream>
#include <string>

void	ftLog(std::string log);

void	increment(int &i)
{
	++i;
}

void	add_lol(std::string &s)
{
	s = s + "lol";
}

void	reverse_bool(bool &b)
{
	b = !b;
}

void	squared(double &d)
{
	d = d * d;
}

void	to_upper(char &c)
{
	c = std::toupper(c);
}

int	main(void)
{

	int	i_arr[] = {100, -2, 42, 0, -700, 1984};
	test_template("int array, f(x) = x + 1", i_arr, 6, increment);

	std::string	s_arr[] = {"hello", "world", "parmi", "nous"};
	test_template("string array, f(s) = s + \"lol\"", s_arr, 4, add_lol);

	bool b_arr[] = {true, false, false, true, true, false, true, false};
	test_template("bool array, f(b) = !b", b_arr, 8, reverse_bool);

	double	d_arr[] = {0.0, 4.2, -5.5, 7.8, 9.12};
	test_template("double array, f(d) = d^2", d_arr, 5, squared);

	char	c_arr[] = {'s', 'h', 'E', 'e', 'S', 'h', '!'};
	test_template("char array, f(c) = C", c_arr, 7, to_upper);


	return (0);
}