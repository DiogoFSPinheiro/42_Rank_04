/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:47:02 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/18 16:28:19 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default constructor called! " << this->_name << " was born! (Scav)"<< std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Naming constructor called! " << this->_name << " was born! (Scav)"<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Copy constructor called! (Scav)" << std::endl;
	*this = other;
}
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor for " << this->_name << " was called! (Scav)" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Assigment constructor for was called! (Scav)" <<std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " <<  this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
	{
		if (this->_energyPoints <= 0)
			std::cout << "ScavTrap " <<  this->_name << " cant attack " << target << ", it's too tired!" << std::endl;
		else
			std::cout << "ScavTrap " <<  this->_name << " cant attack " << target << ", it's dead!" << std::endl;
	}
}
		
}


void ScavTrap::guardGate()
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " <<  this->_name << " is using the Guard Gate skill. You cant touch him!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " <<  this->_name << " cant use the Guard Gate skill, it's too tired!" << std::endl;
}
