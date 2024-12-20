/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 18:24:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <cstdio>

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WRONGCAT: Default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "WRONGCAT: Copy constructor called!" << std::endl;
	*this = other;
}
WrongCat::~WrongCat()
{
	std::cout << "WRONGCAT: Destructor for " << this->_type << " was called!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WRONGCAT: Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong miau" << std::endl;
}

