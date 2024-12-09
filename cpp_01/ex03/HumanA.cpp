/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:45 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 18:39:26 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(const std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

void	HumanA::attack()
{
	std::cout << _name << " attacked with " << _weapon.getType() << " outch!!" << std::endl;
}
 