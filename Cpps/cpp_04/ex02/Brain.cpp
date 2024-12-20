/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/19 14:21:26 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "BRAIN: Default constructor called!" << std::endl;
	this->fillIdeas();
}

Brain::Brain(const Brain& other)
{
	std::cout << "BRAIN: Copy constructor called!" << std::endl;
	*this = other;
}
Brain::~Brain()
{
	std::cout << "BRAIN: Destructor for was called!" << std::endl;
}

Brain &Brain::operator=(const Brain& other)
{
	std::cout << "BRAIN: Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		int	i = -1;
		while(++i < 100)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

void	Brain::setIdeas(unsigned int index, std::string idea)
{
	if (index < 100)
		this->_ideas[index] = idea;
	else
		std::cout << "wrong index" << std::endl;
}

std::string	Brain::getIdeas(unsigned int index) const
{
	if (index < 100)
		return this->_ideas[index];
	return "I can't remember that idea!";
}

void	Brain::fillIdeas()
{
	int i = -1;
	while(++i < 100)
		this->_ideas[i] = "Brain is braining...";
}