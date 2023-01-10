/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:18:52 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/06 12:18:52 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
# define INPUT_HPP

# include "colours.hpp"
# include <locale>
# include <cstdlib>
# include <string>
# include <iostream>
# include <climits>
# include <iomanip>

class	Input
{
	public:
		Input(void);
		Input(Input const &other);
		Input	&operator=(Input const &other);
		~Input(void);

		Input(std::string value);

		std::string const	&getValue(void) const;
		void				setValue(std::string const v);

		operator char(void) const;
		operator int(void) const;
		operator float(void) const;
		operator double(void) const;

		static void	print(char c);
		static void	print(int i);
		static void	print(float f);
		static void	print(double d);

		typedef struct	s_special
		{
			std::string	key;
			std::string	c;
			std::string	i;
			std::string	f;
			std::string	d;	
		}	t_special;
		static void	print(t_special t);

		class	BadCharCastException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Couldn't find a logical cast to char type.");
				}
		};
		class	BadIntCastException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Couldn't find a logical cast to int type.");
				}
		};
		class	BadFloatCastException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Couldn't find a logical cast to float type.");
				}
		};
		class	BadDoubleCastException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Couldn't find a logical cast to double type.");
				}
		};

	private:
		std::string	_value;
};

#endif