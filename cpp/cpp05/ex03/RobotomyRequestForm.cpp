/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:18:09 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 13:44:09 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45)
{
	std::cerr << _GREY << _DIM << "RobotomyRequestForm default constructor called" << _END << std::endl;
	this->target = "DefaultTarget";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form("RobotomyRequestForm", 72, 45)
{
	std::cerr << _GREY << _DIM << "RobotomyRequestForm copy constructor called" << _END << std::endl;
	*this = other;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	std::cerr << _GREY << _DIM << "RobotomyRequestForm assignment operator called" << _END << std::endl;
	this->target = other.target;
	this->setSigned(other.getSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cerr << _GREY << _DIM << "RobotomyRequestForm default destructor called" << _END << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	std::cerr << _GREY << _DIM << "RobotomyRequestForm target constructor called with target "
	<< _YELLOW << target << _END << std::endl;
	this->target = target;
	return ;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (RobotomyRequestForm::NotSignedException());
	else if (this->getExecGrade() < executor.getGrade())
		throw (RobotomyRequestForm::GradeTooLowException());
	else
	{
		srand(time(NULL));
		std::cout << _PURPLE << "* perceuse go brrrr *" << _END << std::endl;
		if (rand() % 2)
		{
			std::cout << _YELLOW << this->target << _PURPLE
			<< " was successfully lobotomized" << _END << std::endl;
		}
		else
		{
			std::cout << _YELLOW << this->target << _PURPLE
			<< " lobotomization failed :(" << _END << std::endl;
		}
	}
	return ;
}