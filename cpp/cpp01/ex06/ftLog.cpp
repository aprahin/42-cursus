/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftLog.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:55:39 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/26 00:10:38 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include <string>
#include <iostream>

void	ftLog(std::string log)
{
	std::cout << _GREY << log << _END << std::endl;
	return ;
}
