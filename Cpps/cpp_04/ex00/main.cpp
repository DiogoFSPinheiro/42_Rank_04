/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/18 22:45:28 by diogosan         ###   ########.fr       */
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
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl;
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << green << "\n--- Test 1: Animal constructors ---" << reset << std::endl;
		Animal whut;
		std::cout << std::endl;
		Animal damn(whut);
		std::cout << std::endl;
		Animal bro;
		bro = whut;
		std::cout << std::endl;

		std::cout << green << "\n--- Test 2: Animal Performances ---" << reset << std::endl;
		Cat catito;
		std::cout << "The " << catito.getType() << " makes: "; catito.makeSound();
		std::cout << std::endl;
		Dog dogito;
		std::cout << "The " << dogito.getType() << " makes: "; dogito.makeSound();
		std::cout << std::endl;

		std::cout << green << "\n--- Test 3: Polymorphism with Animal Pointer ---" << reset << std::endl;
		Animal* animalPtr1 = &catito;
		std::cout << "The " << catito.getType() << " makes: "; animalPtr1->makeSound(); // Should call Cat's makeSound() due to polymorphism
		std::cout << std::endl;
		Animal* animalPtr2 = &dogito;
		std::cout << "The " << dogito.getType() << " makes: "; animalPtr2->makeSound(); // Should call Dog's makeSound() due to polymorphism
		std::cout << std::endl;

		std::cout << green << "\n--- Test 4: Polymorphism with Animal Reference ---" << reset << std::endl;
		Animal& animalRef2 = catito;
		std::cout << "The " << catito.getType() << " makes: "; animalRef2.makeSound(); // Should call Cat's makeSound()
		std::cout << std::endl;
		Animal& animalRef1 = dogito;
		std::cout << "The " << dogito.getType() << " makes: "; animalRef1.makeSound(); // Should call Dog's makeSound()
		std::cout << std::endl;

		std::cout << green << "\n--- Making the wrong cat for tests ---" << reset << std::endl;
		WrongCat wrongCat;
		std::cout << std::endl;

		std::cout << green << "\n--- Test 5: Wrong Polymorphism with WrongCat ---" << reset << std::endl;
		std::cout << "The " << wrongCat.getType() << " makes: "; wrongCat.makeSound();  // WrongAnimal sound
		std::cout << std::endl;

		std::cout << green << "\n--- Test 6: Wrong Polymorphism with Animal Pointer ---" << reset << std::endl;
		WrongAnimal* wrongCatPtr = &wrongCat;
		std::cout << "The " << wrongCatPtr->getType() << " makes: "; wrongCatPtr->makeSound();  // WrongAnimal sound
		std::cout << std::endl;

		std::cout << green << "\n--- Test 7: Wrong Polymorphism with Animal Reference ---" << reset << std::endl;
		WrongAnimal& wrongAnimalRef = wrongCat;
		std::cout << "The " << wrongAnimalRef.getType() << " makes: "; wrongAnimalRef.makeSound();  // WrongAnimal sound
		std::cout << std::endl;

		std::cout << green << "\n--- Destructors ---" << reset << std::endl;
	}
    return 0;
}

