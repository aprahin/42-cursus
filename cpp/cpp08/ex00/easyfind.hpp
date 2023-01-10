/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:26:29 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/07 23:26:29 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class	NoMatchFoundException : public std::exception
{
	public:
		virtual const char	*what(void) const throw()
		{
			return ("Couldn't find value in given container.");
		};
};

template	<typename T>
typename T::iterator easyfind(T haystack, int needle)
{
	typename T::iterator ret = find(haystack.begin(), haystack.end(), needle);
	if (ret == haystack.end())
		throw(NoMatchFoundException());
	return (ret);
}

#endif