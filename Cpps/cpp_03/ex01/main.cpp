/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/18 16:41:53 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

#include <iostream>
#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- Test 1: Default Constructor ---" << std::endl;
    ScavTrap st1;

    std::cout << "\n--- Test 2: Named Constructor ---" << std::endl;
    ScavTrap st2("Scavy");

    std::cout << "\n--- Test 3: Copy Constructor ---" << std::endl;
    ScavTrap st3(st2);

    std::cout << "\n--- Test 4: Assignment Operator ---" << std::endl;
    ScavTrap st4;
    st4 = st1;

    std::cout << "\n--- Test 5: Attack Method (Healthy and Energetic) ---" << std::endl;
    st2.attack("Enemy");

    std::cout << "\n--- Test 6: Attack Method (Dead ScavTrap) ---" << std::endl;
    st2.takeDamage(100); // Kill ScavTrap
    st2.attack("Enemy"); // Attempt to attack after death
	st2.beRepaired(100);

    std::cout << "\n--- Test 7: Attack Method (Exhausted ScavTrap) ---" << std::endl;
    st2.depleteEnergy(50);
    st2.attack("AnotherTarget"); // Attempt to attack with no energy
	st2.depleteEnergy(-50);
	
    std::cout << "\n--- Test 8: Take Damage (Alive ScavTrap) ---" << std::endl;
    st2.takeDamage(25);

    std::cout << "\n--- Test 9: Take Damage (Dead ScavTrap) ---" << std::endl;
    st2.takeDamage(100); // Kill ScavTrap
    st2.takeDamage(10);  // Attempt to damage after death

    std::cout << "\n--- Test 10: Be Repaired (Energetic ScavTrap) ---" << std::endl;
    st2.beRepaired(20);

    std::cout << "\n--- Test 11: Be Repaired (Exhausted ScavTrap) ---" << std::endl;
	st2.depleteEnergy(50);
    st2.beRepaired(10); // Attempt to repair with no energy

    std::cout << "\n--- Test 12: Guard Gate Skill ---" << std::endl;
	st2.depleteEnergy(-50);
    st2.guardGate(); // Use Guard Gate skill successfully

    std::cout << "\n--- Test 13: Guard Gate Skill (Exhausted ScavTrap) ---" << std::endl;
    st2.guardGate(); // Attempt Guard Gate with no energy

    std::cout << "\n--- Test 14: Destructor Calls ---" << std::endl;

    return 0;
}
