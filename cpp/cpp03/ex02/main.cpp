/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:48:54 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/01 17:48:54 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

void	ftLog(std::string log);

int	main(void)
{
	ftLog("Let's instance a ScavTrap named Atraks-1");

	ScavTrap	st_instance("Atraks-1");

	ftLog("As well as a FragTrap named Atraks-2");

	{
		FragTrap	ft_instance("Atraks-2");

		ftLog("Atraks-1 and Atraks-2 both inherit from ClapTrap.");
		ftLog("However, Atraks-2 didn't change its inherited attack.");

		st_instance.attack("Guardian");
		ft_instance.attack("Guardian");

		ftLog("They both have special moves...");

		st_instance.guardGate();
		ft_instance.highFivesGuys();

		ftLog("Let's kill Atraks-2");
	}

	ftLog("And Atraks-1");

	return (0);
}