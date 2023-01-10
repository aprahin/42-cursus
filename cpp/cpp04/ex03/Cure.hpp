/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:13:01 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 17:13:01 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "colours.hpp"
# include <string>
# include <iostream>

class	Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &other);
		Cure	&operator=(Cure const &other);
		virtual ~Cure(void);

		virtual AMateria	*clone(void) const;
		virtual void	use(ICharacter& target); 
};

#endif
