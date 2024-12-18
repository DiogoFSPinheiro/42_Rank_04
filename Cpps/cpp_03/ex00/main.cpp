/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/18 16:22:55 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

int main() {
    std::cout << "\n--- Test 1: Default Constructor ---" << std::endl;
    ClapTrap defaultClap;

    std::cout << "\n--- Test 2: Named Constructor ---" << std::endl;
    ClapTrap namedClap("Clappy");

    std::cout << "\n--- Test 3: Copy Constructor ---" << std::endl;
    ClapTrap copyClap(namedClap);

    std::cout << "\n--- Test 4: Assignment Operator ---" << std::endl;
    ClapTrap assignedClap;
    assignedClap = namedClap;

    std::cout << "\n--- Test 5: Attack Method (Healthy and Energetic) ---" << std::endl;
    namedClap.attack("Enemy");

    std::cout << "\n--- Test 6: Attack Method (Dead ClapTrap) ---" << std::endl;
    defaultClap.takeDamage(15); // Make sure the ClapTrap is "dead"
    defaultClap.attack("Enemy");

    std::cout << "\n--- Test 7: Attack Method (Exhausted ClapTrap) ---" << std::endl;
    namedClap.depleteEnergy(10); // Exhaust energy
    namedClap.attack("Enemy");
	namedClap.depleteEnergy(-10); // Refill energy

    std::cout << "\n--- Test 8: Take Damage (Alive ClapTrap) ---" << std::endl;
    namedClap.takeDamage(5);

    std::cout << "\n--- Test 9: Take Damage (Dead ClapTrap) ---" << std::endl;
    namedClap.takeDamage(10); // Bring HP to 0
    namedClap.takeDamage(5);  // Further damage should not apply

    std::cout << "\n--- Test 10: Be Repaired (Energetic ClapTrap) ---" << std::endl;
    namedClap.beRepaired(3);

    std::cout << "\n--- Test 11: Be Repaired (Exhausted ClapTrap) ---" << std::endl;
    namedClap.depleteEnergy(10);
    namedClap.beRepaired(5);

    std::cout << "\n--- Test 12: Chain Reactions ---" << std::endl;
	namedClap.depleteEnergy(-10);
    namedClap.attack("ChainTarget");
    namedClap.takeDamage(2);
    namedClap.beRepaired(2);
    namedClap.attack("AnotherTarget");

    std::cout << "\n--- Test 13: Destructor Calls ---" << std::endl;
    // All destructors will be called as objects go out of scope

    return 0;
}
