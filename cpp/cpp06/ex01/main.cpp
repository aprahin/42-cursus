/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:13:26 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 19:13:26 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>

void	ftLog(std::string log);

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	ftLog("Let's instance a Data structure...");

	Data	d;

	ftLog("It can hold an int and a string.");
	ftLog("Let's set its values to 42 and \"Hello\".");

	d.i = 42;
	d.s = "Hello";
	std::cout << _WHITE << "I HAS INTEGER VALUE " << _YELLOW << d.i << _END << std::endl;
	std::cout << _WHITE << "I ALSO HAS STRING VALUE " << _YELLOW << d.s << _END << std::endl;
	std::cout << _WHITE << "ME ADDRESS GOT " << _YELLOW << static_cast<void *>(&d) << std::endl;
	
	ftLog("Let's serialize it...");

	uintptr_t	raw = serialize(&d);
	std::cout << _WHITE << "OKAY RAW SERIALIZED DATA GOT " << _BLUE << raw << _END << std::endl;

	ftLog("Let's deserialize it...");

	Data	*d2 = deserialize(raw);

	ftLog("The values should have stayed all the same!");

	std::cout << _WHITE << "BTW I NOW HAS INTEGER VALUE " << _GREEN << d2->i << _END << std::endl;
	std::cout << _WHITE << "ALSO STRING HAS " << _GREEN << d2->s << _END << std::endl;
	std::cout << _WHITE << "FINALLY ADDRESS HAS " << _GREEN << static_cast<void *>(d2) << std::endl;

	ftLog("Bye!");

	return (0);
}