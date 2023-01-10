/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:23:04 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 17:23:04 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "colours.hpp"
# include "AMateria.hpp"
# include <string>
# include <iostream>

class	Character : public ICharacter
{
	public:
		Character(void);
		Character(Character const &other);
		Character	&operator=(Character const &other);
		~Character(void);

		Character(std::string name);
		virtual	std::string const	&getName(void) const;
		virtual void	equip(AMateria *m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter &target);
	private:
		std::string	_name;
		AMateria	*_materias[4];
};

#endif