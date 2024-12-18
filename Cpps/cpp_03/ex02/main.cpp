/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/18 17:07:16 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include "FragTrap.hpp"

int main()
{
	std::cout << "--- Test 1: Default Constructor ---" << std::endl;
    FragTrap ft1;  // Create a FragTrap object using the default constructor
    // Output should be from the default constructor of FragTrap

    std::cout << "\n--- Test 2: Named Constructor ---" << std::endl;
    FragTrap ft2("Fraggy");  // Create a FragTrap object with a specific name
    // Output should be from the named constructor of FragTrap

    std::cout << "\n--- Test 3: Copy Constructor ---" << std::endl;
    FragTrap ft3(ft2);  // Create a copy of ft2 using the copy constructor
    // Output should be from the copy constructor of FragTrap

    std::cout << "\n--- Test 4: Assignment Operator ---" << std::endl;
    FragTrap ft4;  // Create a new FragTrap object
    ft4 = ft2;  // Assign ft2 to ft4 using the assignment operator
    // Output should be from the assignment operator of FragTrap

	std::cout << "\n--- Test 5: Attack Method (Healthy and Energetic) ---" << std::endl;
    ft2.attack("Enemy");

    std::cout << "\n--- Test 6: Attack Method (Dead FragTrap) ---" << std::endl;
    ft2.takeDamage(100);  // Kill FragTrap
    ft2.attack("Enemy");  // Attempt to attack after death
    ft2.beRepaired(100);  // Repair FragTrap

    std::cout << "\n--- Test 7: Attack Method (Exhausted FragTrap) ---" << std::endl;
    ft2.depleteEnergy(100);  // Exhaust energy
    ft2.attack("AnotherTarget");  // Attempt to attack with no energy
    ft2.depleteEnergy(-50);  // Recharge energy

    std::cout << "\n--- Test 8: Take Damage (Alive FragTrap) ---" << std::endl;
    ft2.takeDamage(25);  // Take damage when alive

    std::cout << "\n--- Test 9: Take Damage (Dead FragTrap) ---" << std::endl;
    ft2.takeDamage(100);  // Kill FragTrap
    ft2.takeDamage(10);  // Attempt to damage after death

    std::cout << "\n--- Test 10: Be Repaired (Energetic FragTrap) ---" << std::endl;
    ft2.beRepaired(20);  // Repair FragTrap with enough energy

    std::cout << "\n--- Test 11: Be Repaired (Exhausted FragTrap) ---" << std::endl;
    ft2.depleteEnergy(100);  // Exhaust energy
    ft2.beRepaired(10);  // Attempt to repair with no energy

    std::cout << "\n--- Test 12: High Fives Guys ---" << std::endl;
    ft2.depleteEnergy(-2);
	ft2.highFivesGuys();  // Perform high fives

    std::cout << "\n--- Test 13: High Fives Guys (Exhausted FragTrap) ---" << std::endl;
    ft2.depleteEnergy(100);  // Exhaust energy
    ft2.highFivesGuys();  // Attempt high fives with no energy

    std::cout << "\n--- Test 14: Destructor Calls ---" << std::endl;

    return 0;
}
