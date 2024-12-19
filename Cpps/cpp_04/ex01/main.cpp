/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/19 14:55:14 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <ostream>


int main()
{
	{
		std::cout << green << "\n--- Subject Main ---" << reset << std::endl;
		
		const Animal* dogito = new Dog();
		std::cout<< std::endl;
		const Animal* catito = new Cat();
		std::cout<< std::endl;

		std::cout<< "The " << dogito->getType() << " says: "; dogito->makeSound();
		std::cout<< "The " << catito->getType() << " says: "; catito->makeSound();
		
		std::cout<< std::endl;
		std::cout<< std::endl;
		
		delete dogito;//should not create a leak
		std::cout<< std::endl;
		delete catito;
	}
	std::cout<< std::endl;
	std::cout<< std::endl;
	{
		std::cout << green << "\n--- More Tests: Copy Constructor and Assignment ---" << reset << std::endl;

		Dog originalDog;
		std::cout << std::endl;

		std::cout << yellow <<"Original Dog's Ideas:" << reset << std::endl;
		originalDog.showIdeas(5);
		std::cout << std::endl;

		{
			std::cout << cyan << "Creating a copy using Copy Constructor (test DeepCopy):" << reset << std::endl;
			Dog copiedDog(originalDog);
			std::cout << yellow <<"Copied Dog's Ideas:" << reset << std::endl;
			copiedDog.showIdeas(5);
			std::cout << std::endl;
		}

	}

	std::cout << std::endl;

	{
		std::cout << green << "\n--- Assigment Constructor when the value has a brain ---" << reset << std::endl;

		Dog dog1;
		std::cout << std::endl;
		Dog dog2;
		std::cout << std::endl;
		
		dog1 = dog2;
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << green << "\n--- Array of Animals Test ---" << reset << std::endl;

		const int animalCount = 6;
		Animal* animals[animalCount];

		// Populate array with half Dogs and half Cats
		for (int i = 0; i < animalCount / 2; ++i)
			animals[i] = new Dog();
		for (int i = animalCount / 2; i < animalCount; ++i)
			animals[i] = new Cat();

		std::cout << std::endl;

		// Make each animal in the array make a sound
		std::cout << "Making each Animal in the array make a sound:" << std::endl;
		for (int i = 0; i < animalCount; ++i)
		{
			std::cout << "Animal " << i + 1 << " (" << animals[i]->getType() << ") says: ";
			animals[i]->makeSound();
		}

		std::cout << std::endl;

		// Delete animals
		std::cout << "Deleting Animals:" << std::endl;
		for (int i = 0; i < animalCount; ++i)
		{
			delete animals[i];
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << green << "\n--- Edge Case Tests ---" << reset << std::endl;

		// Edge case: Accessing out-of-bound ideas
		Cat catito;
		std::cout << std::endl;
		std::cout << "Accessing -1th idea (out-of-bounds):" << std::endl;
		catito.showIdeas(-1); std::cout << std::endl;
		std::cout << "Accessing 105th idea (out-of-bounds):" << std::endl;
		catito.showIdeas(105); std::cout << std::endl;

		std::cout << std::endl;
		std::cout << "Done!" << std::endl;
	}
	std::cout << green << "--- End of Tests ---" << reset << std::endl;
	return 0;
}

