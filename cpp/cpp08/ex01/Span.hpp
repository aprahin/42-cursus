/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:31:19 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/08 12:31:19 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "colours.hpp"
# include <string>
# include <iostream>
# include <vector>
# include <algorithm>

class	Span
{
	public:
		Span(Span const &other);
		Span	&operator=(Span const &other);
		~Span(void);

		Span(unsigned int n);
		void	addNumber(int n);
		void	addNumber(
			std::vector<int>::iterator begin,
			std::vector<int>::iterator end);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		std::vector<int>::iterator const	begin(void);
		std::vector<int>::iterator const	end(void);

		class	NotEnoughSpaceException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Span cannot contain any more elements.");
				};
		};

		class	SpanNotFoundException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Not enough element in Span to find a valid span.");
				};
		};
	private:
		Span(void);

		unsigned int		_size;
		std::vector<int>	_elems;
};

#endif