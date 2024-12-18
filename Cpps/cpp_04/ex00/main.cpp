/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/18 19:02:40 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <ostream>

int main()
{
	Animal whut;
	std::cout << std::endl;
	Animal damn(whut);
	std::cout << std::endl;
	Animal shit;
	shit = whut;
	std::cout << std::endl;

	Cat catito;
	std::cout << "The " << catito.getType()<< " makes: "; catito.makeSound();
	std::cout << std::endl;

	Dog dogito;
	std::cout << "The " << dogito.getType()<< " makes: "; dogito.makeSound();
	std::cout << std::endl;

	

    return 0;
}
