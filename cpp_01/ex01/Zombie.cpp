/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:27:06 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 16:52:38 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << green << _name << red <<" killed!\n" << reset ;
}

void	Zombie::set_name(std::string name)
{
	_name = name;
}
