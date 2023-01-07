/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:00:17 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/26 01:33:20 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "colours.hpp"
#include <sys/wait.h>
#define BUFFER_SIZE 8

void	ftLog(std::string log);

std::string	searchAndReplace(std::string str, std::string from, std::string to)
{
	size_t		pos;
	size_t		last_pos;
	std::string	replaced;

	last_pos = 0;
	pos = 0;
	while ((pos = str.find(from, pos)) != std::string::npos)
	{
		while (last_pos < pos)
			replaced += str[last_pos++];
		replaced += to;
		pos += from.length();
		last_pos = pos;	
	}
	replaced += str.c_str() + last_pos;
	return (replaced);
}

std::string	readEverything(std::ifstream &file)
{
	std::string	stash;
	char		c;

	while (file.get(c))
		stash += c;
	return (stash);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./sed [file] [from] [to]" << std::endl;
		return (1);
	}
	else if (strlen(av[2]) == 0)
	{
		std::cout << "./sed: word to replace cannot be empty" << std::endl;
		return (1);
	}

	std::ifstream	in_file(av[1]);	
	if (in_file.fail())
	{
		std::cout << "./sed: ";
		std::cout << _RED << av[1] << _END;
		std::cout << ": No such file or directory" << std::endl;
		return (1);
	}

	std::string		out_file_name = av[1] + static_cast<std::string>(".replace");
	std::ofstream	out_file(out_file_name.c_str());

	std::string		content = readEverything(in_file);
	out_file << searchAndReplace(content, av[2], av[3]);

	in_file.close();
	out_file.close();
	return (0);
}