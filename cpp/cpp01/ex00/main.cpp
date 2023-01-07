/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:43:54 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 18:59:35 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	ftLog(std::string log);

int	main(void)
{
	ftLog("Let's summon a Zombie in my main...");

	Zombie	stack_zombie("Stack Zombie");
	stack_zombie.announce();
	
	ftLog("Now what about a Zombie using newZombie...?"); 

	Zombie	*heap_zombie = newZombie("Heap Zombie");
	heap_zombie->announce();

	ftLog("Finally, let's summon a temporary Zombie...");
	
	randomChump("Temp Zombie");
	
	ftLog("...and he's gone :(");
	ftLog("I'll delete my HeapZombie:");
	
	delete heap_zombie;
	
	ftLog("Time to return...");
	return (0);
}