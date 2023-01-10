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
#include "Array.hpp"
#include <iostream>
#include <string>

void	ftLog(std::string log);

template	<typename T>
void	printArray(Array<T> &arr)
{
		std::cout << _BLUE << "[";
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i];
			if (i != arr.size() - 1)
				std::cout << ", ";
		}
		std::cout << "]" << _END << std::endl;
}

int	main(void)
{
	try
	{
		ftLog("Let's instance an Array with type int of size 10...");

		Array<int>	arr(10);

		ftLog("...and print its content!");

		printArray(arr);

		ftLog("I can modify a bunch of values...");

		arr[7] = 42;
		arr[2] = -100;
		arr[5] = 25;
		printArray(arr);

		ftLog("I can also copy it!");

		Array<int>	arr2 = arr;
		printArray(arr);
		printArray(arr2);

		ftLog("Since this is a deep copy, I can modify one array without affecting the other.");

		arr2[2] = 1337;
		arr2[6] = -11;
		printArray(arr);
		printArray(arr2);

		ftLog("I can call array.size() on both of them...");

		std::cout << _YELLOW << arr.size() << std::endl;
		std::cout << arr2.size() << _END << std::endl;

		ftLog("Of course, this also works for any type.");
		ftLog("Let's try it with strings!");

		Array<std::string>	arr3(4);
		printArray(arr3);

		ftLog("Every string is initialized to an empty string. Let's fill it up...");

		arr3[0] = "HI";
		arr3[1] = "YOUR ARRAY IS";
		arr3[2] = "DAMN ARRAY";
		arr3[3] = "KTHXBYE";
		printArray(arr3);

		ftLog("What happens if we try to access an index beyond the size of the array?");

		arr3[4] = "AMOGUS!";
	}
	catch (std::exception &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}

	return (0);
}