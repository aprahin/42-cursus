/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:40:57 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/17 14:47:00aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "colours.hpp"
# include <string>
# include <iostream>
# include <iomanip>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		void	setInfo(
			std::string	first_name,
			std::string	last_name,
			std::string	nickname,
			std::string	phone_number,
			std::string	secret
		);
		void	printShortInfo(int index) const;
		void	printLongInfo(void) const;
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _secret;
};

#endif
