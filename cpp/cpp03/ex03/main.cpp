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
#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

void	ftLog(std::string log);

int	main(void)
{
	ftLog("Let's instance a DiamondTrap named Ada-1");

	DiamondTrap	dt_instance("Ada-1");

	ftLog("Her stats and attack should be a mix between ScavTrap and FragTrap");

	dt_instance.attack("Fallen");
	dt_instance.takeDamage(10);

	ftLog("She also has a special move!");

	dt_instance.whoAmI();

	ftLog("Let's end this...");

	return (0);
}