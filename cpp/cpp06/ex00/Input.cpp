/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:44:26 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/06 12:44:26 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

Input::Input(void) : _value("DefaultValue")
{
	std::cerr << _GREY << _DIM << "Input default constructor called" << _END << std::endl;
	return ;
}

Input::Input(Input const &other) : _value(other.getValue())
{
	std::cerr << _GREY << _DIM << "Input copy constructor called" << _END << std::endl;
	return ;
}

Input	&Input::operator=(Input const &other)
{
	std::cerr << _GREY << _DIM << "Input assignment operator called" << _END << std::endl;
	this->_value = other.getValue();
	return (*this);
}

Input::~Input(void)
{
	std::cerr << _GREY << _DIM << "Input default destructor called" << _END << std::endl;
	return ;
}

Input::Input(std::string value) : _value(value)
{
	std::cerr << _GREY << _DIM << "Input named constructor called with value "
	<< _YELLOW << this->getValue() << _END << std::endl;
	return ;
}

std::string const	&Input::getValue(void) const
{
	return (this->_value);
}

void	Input::setValue(std::string const v)
{
	this->_value = v;
}

Input::operator char(void) const
{
	if (this->getValue().length() != 1
		|| std::isdigit((this->getValue())[0])
		|| !std::isprint((this->getValue())[0]))
	{
		throw (BadCharCastException());
		return (-1);
	}
	return ((this->getValue())[0]);
}

Input::operator int(void) const
{
	int			i = 0;
	std::string const	&str = this->getValue();
	long long int	j = std::atoll(str.c_str());
	if (j < INT_MIN || j > INT_MAX)
	{
		throw (BadIntCastException());
		return (0);
	}

	while (std::isspace(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (str[i] == '\0' || !std::isdigit(str[i]))
	{
		throw (BadIntCastException());
		return (0);
	}
	++i;
	while (str[i] != '\0')
	{
		if (!std::isdigit(str[i]))
		{
			/*if (str[i] == '.' || str[i] == 'f')
			{*/
				throw(BadIntCastException());
				return (0);
			//}
			break ;
		}
		++i;
	}
	return (std::atoi(str.c_str()));
}

Input::operator float(void) const
{
	int			i = 0;
	std::string const	&str = this->getValue();
	long long int	j = std::atoll(str.c_str());
	if (j < INT_MIN || j > INT_MAX)
	{
		throw (BadFloatCastException());
		return (0);
	}

	while (std::isspace(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (str[i] == '\0' || (!std::isdigit(str[i]) && str[i] != '.'))
	{
		throw (BadFloatCastException());
		return (0);
	}
	++i;
	bool	dotted = false;
	while (str[i] != '\0' && str[i] != 'f')
	{
		if (!std::isdigit(str[i]))
		{
			if (!std::isdigit(str[i]) && str[i] != '.')
			{
				throw(BadFloatCastException());
				return (0);
			}
			if (str[i] == '.' && dotted)
			{
				throw(BadFloatCastException());
				return (0);
			}
			else
			{
				dotted = true;
			}
		}
		++i;
	}
	if (str[i] == '\0' || str[i + 1] != '\0')
	{
		throw(BadFloatCastException());
		return (0);
	}
	return (static_cast<float>(std::atof(str.c_str())));
}

Input::operator double(void) const
{
	int			i = 0;
	std::string const	&str = this->getValue();
	long long int	j = std::atoll(str.c_str());
	if (j < INT_MIN || j > INT_MAX)
	{
		throw (BadDoubleCastException());
		return (0);
	}

	while (std::isspace(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (str[i] == '\0' || (!std::isdigit(str[i]) && str[i] != '.'))
	{
		throw (BadDoubleCastException());
		return (0);
	}
	++i;
	bool	dotted = false;
	while (str[i] != '\0')
	{
		if (!std::isdigit(str[i]))
		{
			if (!std::isdigit(str[i]) && str[i] != '.')
			{
				throw(BadDoubleCastException());
				return (0);
			}
			if (str[i] == '.' && dotted)
			{
				throw(BadDoubleCastException());
				return (0);
			}
			else
			{
				dotted = true;
			}
		}
		++i;
	}
	if (!dotted)
	{
		throw(BadDoubleCastException());
		return (0);
	}
	return (std::atof(str.c_str()));
}

void	Input::print(char c)
{
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	std::cout << _WHITE << "char: \'" << _GREEN << c << "\'" << _END << std::endl;
	std::cout << _WHITE << "int: " << _YELLOW << i << _END << std::endl;
	std::cout << _WHITE << "float: " << _BLUE << f << ".0f" << _END << std::endl;
	std::cout << _WHITE << "double: " << _RED << d << ".0" << _END << std::endl;
	return ;
}

void	Input::print(int i)
{
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	std::cout << _WHITE << "char: " << _GREEN;
	if (i < CHAR_MIN || i > CHAR_MAX || !std::isprint(i))
		std::cout << "Non displayable";
	else
		std::cout << "\'" << c << "\'";
	std::cout << _END << std::endl;

	std::cout << _WHITE << "int: " << _YELLOW << i << _END << std::endl;
	(void) f;
	std::cout << _WHITE << "float: " << _BLUE << i << ".0f" << _END << std::endl;
	(void) d;
	std::cout << _WHITE << "double: " << _RED << i << ".0" << _END << std::endl;
	return ;
}

void	Input::print(float f)
{
	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);

	std::cout << _WHITE << "char: " << _GREEN;
	if (i < CHAR_MIN || i > CHAR_MAX || !std::isprint(i))
		std::cout << "Non displayable";
	else
		std::cout << "\'" << c << "\'";
	std::cout << _END << std::endl;

	std::cout << _WHITE << "int: " << _YELLOW << i << _END << std::endl;
	if (f == i)
		std::cout << _WHITE << "float: " << _BLUE << i << ".0f" << _END << std::endl;
	else
		std::cout << _WHITE << "float: " << _BLUE << f << "f" << _END << std::endl;
	if (d == i)
		std::cout << _WHITE << "double: " << _RED << i << ".0" << _END << std::endl;
	else
		std::cout << _WHITE << "double: " << _RED << d << _END << std::endl;
	return ;
}

void	Input::print(double d)
{
	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	std::cout << _WHITE << "char: " << _GREEN;
	if (i < CHAR_MIN || i > CHAR_MAX || !std::isprint(i))
		std::cout << "Non displayable";
	else
		std::cout << "\'" << c << "\'";
	std::cout << _END << std::endl;

	std::cout << _WHITE << "int: " << _YELLOW << i << _END << std::endl;
	if (f == i)
		std::cout << _WHITE << "float: " << _BLUE << i << ".0f" << _END << std::endl;
	else
		std::cout << _WHITE << "float: " << _BLUE << f << "f" << _END << std::endl;
	if (d == i)
		std::cout << _WHITE << "double: " << _RED << i << ".0" << _END << std::endl;
	else
		std::cout << _WHITE << "double: " << _RED << d << _END << std::endl;
	return ;
}

void	Input::print(t_special t)
{
	std::cout << _WHITE << "char: " << _GREEN << t.c << _END << std::endl;
	std::cout << _WHITE << "int: " << _YELLOW << t.i << _END << std::endl;
	std::cout << _WHITE << "float: " << _BLUE << t.f << _END << std::endl;
	std::cout << _WHITE << "double: " << _RED << t.d << _END << std::endl;
}
