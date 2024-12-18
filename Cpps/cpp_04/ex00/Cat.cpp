/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 18:24:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <cstdio>

Cat::Cat()
{
	_type = "Cat";
	std::cout << "CAT: Default constructor called!" << std::endl;
}

Cat::Cat(const Cat& other)
{
	std::cout << "CAT: Copy constructor called!" << std::endl;
	*this = other;
}
Cat::~Cat()
{
	std::cout << "CAT: Destructor for " << this->_type << " was called!" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
	std::cout << "CAT: Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout <<"miaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaau" <<std::endl;
}

