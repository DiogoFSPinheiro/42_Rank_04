/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 18:24:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <cstdio>

Animal::Animal()
{
	_type = "Animal";
	std::cout << "ANIMAL: Default constructor called!" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "ANIMAL: Copy constructor called!" << std::endl;
	*this = other;
}
Animal::~Animal()
{
	std::cout << "ANIMAL: Destructor for " << this->_type << " was called!" << std::endl;
}

Animal &Animal::operator=(const Animal& other)
{
	std::cout << "ANIMAL: Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound!" << std::endl;;
}

std::string Animal::getType() const
{
	return _type;
}

