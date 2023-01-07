/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:32:21 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/01 18:32:21 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP 
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(DiamondTrap const &other);
		DiamondTrap	&operator=(DiamondTrap const &other);
		~DiamondTrap(void);

		DiamondTrap(std::string name);

		void	attack(std::string const &target);
		void	whoAmI(void);
	private:
		std::string	_name;
};

#endif