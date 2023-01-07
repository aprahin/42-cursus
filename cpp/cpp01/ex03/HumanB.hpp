/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:31:29 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 22:47:50 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
	private:
		const std::string	_name;
		Weapon				*_weapon;
};

#endif