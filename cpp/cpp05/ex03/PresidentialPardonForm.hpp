/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:17:14 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 11:44:45 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include "colours.hpp"
# include <string>
# include <iostream>

class	PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);
		~PresidentialPardonForm(void);

		PresidentialPardonForm(std::string target);
		void	execute(Bureaucrat const &executor) const;
};

#endif