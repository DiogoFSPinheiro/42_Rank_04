/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 18:24:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <cstdio>

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AANIMAL: Default constructor called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "AANIMAL: Copy constructor called!" << std::endl;
	*this = other;
}
AAnimal::~AAnimal()
{
	std::cout << "AANIMAL: Destructor for " << this->_type << " was called!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AANIMAL: Assigment constructor for was called!" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << "Some generic Aanimal sound!" << std::endl;;
}

std::string AAnimal::getType() const
{
	return _type;
}

