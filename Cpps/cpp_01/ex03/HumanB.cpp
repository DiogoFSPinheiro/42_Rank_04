/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:36 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 21:35:47 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string name) : _name(name)
{
	_weapon = NULL;
}

HumanB::HumanB(const std::string name, Weapon *weapon)
{
	_name = name;
	_weapon = weapon;
}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << " outch!!" << std::endl;
	else
		std::cout << _name << " attacks with their ... no weapon?" << " damn..." << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}