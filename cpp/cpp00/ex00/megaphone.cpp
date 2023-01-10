/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:40:38 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/17 11:29:41 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	(void)	av;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}	
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; j < (int) strlen(av[i]); j++)
				std::cout << (char) toupper(av[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}