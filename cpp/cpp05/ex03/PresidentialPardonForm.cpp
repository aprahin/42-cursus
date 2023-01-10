/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:18:09 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 13:44:09 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5)
{
	std::cerr << _GREY << _DIM << "PresidentialPardonForm default constructor called" << _END << std::endl;
	this->target = "DefaultTarget";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form("PresidentialPardonForm", 25, 5)
{
	std::cerr << _GREY << _DIM << "PresidentialPardonForm copy constructor called" << _END << std::endl;
	*this = other;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	std::cerr << _GREY << _DIM << "PresidentialPardonForm assignment operator called" << _END << std::endl;
	this->target = other.target;
	this->setSigned(other.getSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cerr << _GREY << _DIM << "PresidentialPardonForm default destructor called" << _END << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
	std::cerr << _GREY << _DIM << "PresidentialPardonForm target constructor called with target "
	<< _YELLOW << target << _END << std::endl;
	this->target = target;
	return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (PresidentialPardonForm::NotSignedException());
	else if (this->getExecGrade() < executor.getGrade())
		throw (PresidentialPardonForm::GradeTooLowException());
	else
	{
		std::cout << _YELLOW << this->target << _PURPLE
		<< " was pardonned by Zaphod Beeblebrox." << _END << std::endl;
	}
	return ;
}