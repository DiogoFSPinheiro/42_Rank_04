/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 18:24:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <cstdio>

WrongAnimal::WrongAnimal()
{
	_type = "Unknown";

	std::cout << "WRONGANIMAL: Default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WRONGANIMAL: Copy constructor called!" << std::endl;
	*this = other;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WRONGANIMAL: Destructor for " << this->_type << " was called!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WRONGANIMAL: Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound!!" << std::endl;
}

std::string WrongAnimal::getType()
{
	return _type;
}

