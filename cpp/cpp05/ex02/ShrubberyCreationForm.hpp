/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:17:14 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 13:59:46 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include "colours.hpp"
# include <string>
# include <iostream>

class	ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm(std::string target);
		void	execute(Bureaucrat const &executor) const;
};

#endif