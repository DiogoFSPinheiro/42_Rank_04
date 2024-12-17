/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/17 18:39:02 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

int main(void)
{
	ClapTrap a;
	ClapTrap b("Gabriel");
	ClapTrap c;
	c = b;
	
	a.getName();
	b.getName();
	c.getName();

	std::cout << std::endl;
	a.attack(b.getName());
	a.takeDamage(10);
	a.beRepaired(10);
	a.depleteEnergy(9);
	a.attack(b.getName());
	a.beRepaired(10);
	
	return 0;
}