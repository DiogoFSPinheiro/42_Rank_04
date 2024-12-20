/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/20 16:32:01 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <ostream>


int main()
{
    std::cout << green << "\n--- Testing Abstract AAnimal ---" << reset << std::endl;
    //AAnimal abstractAnimal; // This should not compile!

    std::cout << "\nCreating a Dog object..." << std::endl;
    Dog doggo;
	std::cout<< "The " << doggo.getType() << " says: "; doggo.makeSound();
    std::cout << std::endl;
	
    std::cout << "\nCreating a Cat object..." << std::endl;
    Cat kitty;
	std::cout<< "The " << kitty.getType() << " says: "; kitty.makeSound();
	std::cout << std::endl;


    std::cout << green << "\n--- Polymorphism with Abstract AAnimal ---" << reset << std::endl;

    AAnimal* polymorphicDog = new Dog();
    std::cout<< "The " << polymorphicDog->getType()<< " says: "; polymorphicDog->makeSound();
	std::cout << std::endl;
	delete polymorphicDog;
	
	std::cout << std::endl;
	
    AAnimal* polymorphicCat = new Cat();
	std::cout<< "The " << polymorphicCat->getType()<< " says: "; polymorphicCat->makeSound(); // Should call Cat's makeSound()
	std::cout << std::endl;
	delete polymorphicCat;

	std::cout << green << "\n--- Normal Destructors" << reset << std::endl;

    return 0;
}


