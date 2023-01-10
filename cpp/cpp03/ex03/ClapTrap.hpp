/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:19:13 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/01 17:19:13 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "colours.hpp"
# include <string>
# include <iostream>

class	ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap &other);
		ClapTrap	&operator=(const ClapTrap &other);
		~ClapTrap(void);

		ClapTrap(std::string name);
		ClapTrap(
			std::string name,
			int	hp,
			int	ep,
			int	dmg
		);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int	amount);
		void	beRepaired(unsigned int	amount);
	protected:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_dmg;
};

#endif