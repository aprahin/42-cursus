/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:57:21 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 16:57:21 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"
# include "colours.hpp"
# include <string>
# include <iostream>

class	IMateriaSource
{
	public:
		virtual	~IMateriaSource() {}
		virtual void	learnMateria(AMateria *m) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};

#endif