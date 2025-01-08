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
	this->_brain = new Brain();
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
	delete this->_brain;
}

Cat &Cat::operator=(const Cat& other)
{
	std::cout << "DOG: Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaau" <<  std::endl;
}

void Cat::showIdeas(int nbr) const
{
	int i = -1;
	if (nbr > 100)
	{
		std::cout << "I can only get 100 Ideas" <<  std::endl;
		return ;
	}
		
	if (nbr < 0)
	{
		std::cout << "I can't remember negative Ideas" <<  std::endl;
		return ;
	}

	while (++i < nbr-1)
		std::cout << this->_brain->getIdeas(i) <<std::endl;
}
