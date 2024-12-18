/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:47:02 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/18 17:01:23 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_name = "Mickel";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default constructor called! " << this->_name << " was born! (Frag)"<< std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Naming constructor called! " << this->_name << " was born! (Frag)"<< std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "Copy constructor called! (Frag)" << std::endl;
	*this = other;
}
FragTrap::~FragTrap()
{
	std::cout << "Destructor for " << this->_name << " was called! (Frag)" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Assigment constructor for was called! (Frag)" <<std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "FragTrap "<< this->_name << " wants to High Five...run!!!" << std::endl;
		this->_energyPoints--;
	}
		
	else
		std::cout << "FragTrap "<< this->_name << " wants to High Five...but it cant eheheh!" << std::endl;
}