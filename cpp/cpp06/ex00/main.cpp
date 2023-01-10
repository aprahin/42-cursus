/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:13:26 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 19:13:26 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include "Input.hpp"
#include <iostream>
#include <string>
#include <iomanip>

void	ftLog(std::string log);

bool	checkSpecial(std::string s, Input::t_special *t)
{
	Input::t_special	list[] = {
		{"+inff", "impossible", "impossible", "inff", "inf"},
		{"inff", "impossible", "impossible", "inff", "inf"},
		{"-inff", "impossible", "impossible", "-inff", "-inf"},
		{"nanf", "impossible", "impossible", "nanf", "nan"},
		{"+inf", "impossible", "impossible", "inff", "inf"},
		{"inf", "impossible", "impossible", "inff", "inf"},
		{"-inf", "impossible", "impossible", "-inff", "-inf"},
		{"nan", "impossible", "impossible", "nanf", "nan"},
		{"", "", "", "", ""}
	};
	int	i = 0;
	while ((list[i].key).length() != 0)
	{
		if (s == list[i].key)
		{
			t->key = list[i].key;
			t->c = list[i].c;
			t->i = list[i].i;
			t->f = list[i].f;
			t->d = list[i].d;
			return (true);
		}
		++i;
	}
	return (false);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ftLog("Usage: ./cast [(char), (int), (float), (double)]");
		return (1);
	}
	{
		Input::t_special	special;
		if (checkSpecial(av[1], &special))
		{
			Input::print(special);
			return (0);
		}
	}
	try 
	{
		Input	i(av[1]);
		char	a = static_cast<char>(i);
		Input::print(a);
		return (0);
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << std::endl;
	}
	try
	{
		Input	i(av[1]);
		int		a = static_cast<int>(i);
		Input::print(a);
		return (0);
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << std::endl;
	}
	try
	{
		Input	i(av[1]);
		float		a = static_cast<float>(i);
		Input::print(a);
		return (0);
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << std::endl;
	}
	try
	{
		Input	i(av[1]);
		double		a = static_cast<double>(i);
		Input::print(a);
		return (0);
	}
	catch (std::exception &e)
	{
		std::cerr << _RED << e.what() << std::endl;
	}
	Input::t_special special = {"none", "impossible", "impossible", "impossible", "impossible"};
	Input::print(special);
	return (0);
}