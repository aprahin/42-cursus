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
#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <list>

void	ftLog(std::string log);

void	mainWithList(void)
{
	ftLog("main() with List");

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
	return ;
}

void	test(void)
{
	ftLog("Let's fill our MutantStack with numbers.");

	MutantStack<float> ms;
	for (float f = 0; f < 5; f += 0.3)
		ms.push(f);
	
	ftLog("Now let's print its content using our custom iterators!");

	std::cout << _GREEN << "[";
	for (MutantStack<float>::iterator it = ms.begin(); it != ms.end(); it++)
		std::cout << *it << " ";
	std::cout << "]" << _END << std::endl;	
}

int	main(void)
{
	{
		ftLog("main() with MutantStack");

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	mainWithList();
	test();
	return 0;
}