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
#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

void	ftLog(std::string log);

void	printNumber(int n)
{
	std::cout << n << " ";
}

template <typename T>
void	try_find(T &ctr, int n)
{
	try
	{
		std::cout << _YELLOW << _BOLD << "TO FIND" << _END << std::endl;
		std::cout << _GREEN << n << _END << std::endl;

		std::cout << _YELLOW << _BOLD << "FOUND" << _END << std::endl;
		std::cout << _GREEN << *easyfind(ctr, n) << _END << std::endl;
	}
	catch (NoMatchFoundException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}	
}

int	main(void)
{
	{
		std::vector<int>	vec;
		vec.push_back(5);
		vec.push_back(-42);
		vec.push_back(100);
		vec.push_back(7);
		vec.push_back(0);
		vec.push_back(42);
		std::cout << _GREY << "=========================" << _END << std::endl;
		std::cout << _CYAN << _BOLD << "TEST: vector" << _END << std::endl;

		std::cout << _YELLOW << _BOLD << "CONTENTS" << _END << std::endl;
		std::cout << _GREEN;
		std::for_each(vec.begin(), vec.end(), printNumber);
		std::cout << _END << std::endl;

		try_find(vec, 7);
		try_find(vec, 1337);
		try_find(vec, 0);
		try_find(vec, -42);
		try_find(vec, 420);
		std::cout << _GREY << "=========================" << _END << std::endl;
	}
	{
		std::list<int>	lst;
		lst.push_back(7);
		lst.push_back(-5);
		lst.push_back(13714);
		lst.push_back(0);
		lst.push_back(328);
		std::cout << _GREY << "=========================" << _END << std::endl;
		std::cout << _CYAN << _BOLD << "TEST: list" << _END << std::endl;

		std::cout << _YELLOW << _BOLD << "CONTENTS" << _END << std::endl;
		std::cout << _GREEN;
		std::for_each(lst.begin(), lst.end(), printNumber);
		std::cout << _END << std::endl;

		try_find(lst, 7);
		try_find(lst, 42);
		try_find(lst, 0);
		try_find(lst, 420);
		try_find(lst, 13714);
		std::cout << _GREY << "=========================" << _END << std::endl;
	}
	{
		std::deque<int>	deq;
		deq.push_back(12);
		deq.push_back(21374);
		deq.push_back(-123894);
		deq.push_back(374);
		deq.push_back(1);
		deq.push_back(-42);
		std::cout << _GREY << "=========================" << _END << std::endl;
		std::cout << _CYAN << _BOLD << "TEST: deque" << _END << std::endl;

		std::cout << _YELLOW << _BOLD << "CONTENTS" << _END << std::endl;
		std::cout << _GREEN;
		std::for_each(deq.begin(), deq.end(), printNumber);
		std::cout << _END << std::endl;

		try_find(deq, 21374);
		try_find(deq, 1337);
		try_find(deq, 1);
		try_find(deq, -42);
		try_find(deq, 374);
		std::cout << _GREY << "=========================" << _END << std::endl;
	}
	return (0);
}