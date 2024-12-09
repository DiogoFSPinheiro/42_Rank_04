/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:36 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 19:03:00 by diogosan         ###   ########.fr       */
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
	std::cout << _name << " attacked with " << _weapon->getType() << " outch!!" << std::endl;
}

void	set_weapon(Weapon *weapon)
{
	_weapon = weapon;
}