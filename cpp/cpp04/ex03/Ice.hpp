/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:13:01 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 17:13:01 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "colours.hpp"
# include <string>
# include <iostream>

class	Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &other);
		Ice	&operator=(Ice const &other);
		virtual ~Ice(void);

		virtual AMateria	*clone(void) const;
		virtual void	use(ICharacter& target); 
};

#endif
