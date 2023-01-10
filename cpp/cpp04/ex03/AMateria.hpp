/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:47:34 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 16:47:34 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "colours.hpp"
# include <string>
# include <iostream>
# include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	public:
		AMateria(void);
		AMateria(AMateria const &other);
		AMateria	&operator=(AMateria const &other);
		virtual ~AMateria(void);

		AMateria(std::string const &type);
		std::string const	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void	use(ICharacter& target);
	protected:
		std::string	type;
};

#endif