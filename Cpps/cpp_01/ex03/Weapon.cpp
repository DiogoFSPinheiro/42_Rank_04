/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:47 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 18:38:06 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{	
	_type = "Unknown";
}

Weapon::Weapon(std::string type)
{	
	_type = type;
}

Weapon::~Weapon()
{
	std::cout << _type << " dropped!\n";
}

std::string& Weapon::getType()
{
	return _type;
}

void		Weapon::setType(std::string type)
{
	_type = type;
}