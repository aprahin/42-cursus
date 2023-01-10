/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:52:34 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 17:52:34 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "colours.hpp"
# include "AMateria.hpp"
# include <string>
# include <iostream>

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &other);
		~MateriaSource(void);

		virtual void	learnMateria(AMateria *m);
		virtual AMateria	*createMateria(std::string const &type);
	private:
		AMateria	*_materias[4];
};

#endif