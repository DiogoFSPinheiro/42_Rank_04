/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 18:24:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdio>

ClapTrap::ClapTrap()
{
	_name = "Mickel";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Default constructor called! " << this->_name << " was born! (Clap)"<< std::endl;
}

ClapTrap::ClapTrap(const std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Naming constructor called! " << this->_name << " was born! (Clap)"<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called (Clap)" << std::endl;
	*this = other;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor for " << this->_name << " was called! (Clap)" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Assigment constructor for was called! (Clap)" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

std::string ClapTrap::getName()
{
	return this->_name;
}


void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " <<  this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
	{
		if (this->_energyPoints <= 0)
			std::cout << "ClapTrap " <<  this->_name << " cant attack " << target << ", it's too tired!" << std::endl;
		else
			std::cout << "ClapTrap " <<  this->_name << " cant attack " << target << ", it's dead!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't take " << amount <<" of damage. Stop! It's dead already!" << std::endl;
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " sufered "<< amount << " points of damage!" << std::endl;
		if (this->_hitPoints < 0)
			this->_hitPoints = 0;
	}
}



void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repared "<< amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cant repair it self it's too tired!" << std::endl;
		
}

void ClapTrap::depleteEnergy(int amount)
{
	if (amount < 0)
		std::cout << "Charging " << this->_name <<std::endl;
	this->_energyPoints -= amount;
	if (this->_energyPoints < 0)
		_energyPoints = 0;
}

int ClapTrap::getHp()
{
	return this->_hitPoints;
}