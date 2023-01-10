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
#include "Span.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

void	ftLog(std::string log);

void	printNumber(int n)
{
	std::cout << n << " ";
}

void	exec_test(int size, int range)
{
	std::cout << _GREY << "==========================" << _END << std::endl;
	std::cout << _CYAN << _BOLD << "TEST: " << size << " values" << _END << std::endl;
	Span	s(size);
	std::vector<int>	to_add;
	for (int _ = 0; _ < size; _++)	
		to_add.push_back(rand() % (2 * range) - range);
	s.addNumber(to_add.begin(), to_add.end());
	std::cout << _YELLOW << _BOLD << "VALUES" << _END << std::endl;
	std::cout << _GREEN << "[";
	std::for_each(s.begin(), s.end(), printNumber);	
	std::cout << "]" << _END << std::endl;
	std::cout << _YELLOW << _BOLD << "SHORTEST SPAN" << _END << std::endl;
	std::cout << _GREEN << s.shortestSpan() << _END << std::endl;
	std::cout << _YELLOW << _BOLD << "LONGEST SPAN" << _END << std::endl;
	std::cout << _GREEN << s.longestSpan() << _END << std::endl;
	std::cout << _GREY << "==========================" << _END << std::endl;
}

int	main(void)
{
	srand(time(NULL));
	try
	{
		exec_test(2, 100);
		exec_test(3, 10);
		exec_test(3, 50);
		exec_test(3, 100);
		exec_test(5, 10);
		exec_test(10, 50);
		exec_test(10000, 10000);
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}

	return (0);
}