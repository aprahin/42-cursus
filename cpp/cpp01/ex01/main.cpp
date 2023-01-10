/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:51:56 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 20:05:48 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void	ftLog(std::string log);
Zombie	*zombieHorde(int N, std::string name);

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ftLog("Usage: ./horde [size] [name]");
		return (1);
	}
	int	nb = std::atoi(av[1]);
	if (nb <= 0)
	{
		ftLog("Horde size must be an integer greater than zero");
		return (1);
	}
	std::string	name = av[2];
	
	ftLog("Summoning a Zombie Horde using zombieHorde()...");
	
	Zombie	*zombie_ptr = zombieHorde(nb, name);
	if (zombie_ptr == NULL)
	{
		ftLog("There was an error with the summoning...");
		return (1);
	}
	
	ftLog("Each Zombie shall now announce its presence!");

	for (int i = 0; i < nb; i++)
		zombie_ptr[i].announce();
	
	ftLog("The sun rises...");
	
	delete [] zombie_ptr;

	ftLog("Time to return...");
	return (0);		
}
