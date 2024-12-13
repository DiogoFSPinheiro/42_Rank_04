/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 21:34:47 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>
#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void){
	// My testes
	{
	Weapon bonk("Mega Bonker");
	Weapon Ubonk("Ultra Mega Bonker");
	
	HumanA Saul = HumanA("Saul", bonk);
	HumanB Paul = HumanB("Paul");
	Saul.attack();
	Paul.attack();
	Paul.setWeapon(Ubonk);
	Paul.attack();
	}
	std::cout << std::endl << std::endl;
	// Intra tests
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
