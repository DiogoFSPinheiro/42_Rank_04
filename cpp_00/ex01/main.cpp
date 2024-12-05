/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:22:21 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/05 23:28:59 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <cstdlib>
#include <limits>

int main()
{
    Contact person;
	Phonebook PhoneBook;
	std::string command;

	PhoneBook.fill_contacts_tester();
	int i = 0;
	while(43)
 	{
		
		std::cout << "Welcome to my PhoneBook!!" << std::endl;
		std::cout << "Use: ADD, SEARCH or EXIT" << std::endl << std::endl;
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			if(PhoneBook.add_contact(i) == true)
				i++;
			else
			{
				std::cout << "EOF detected. Closing..." << std::endl;
				break ;
			}
				
		}
		else if (command == "SEARCH")
		{
			PhoneBook.print_contacts();
			std::cout << "Choose index number: " ;
			std::getline(std::cin, command);
			int index = std::atoi(command.c_str());
			PhoneBook.print_single_contact(index);
		}
		else if (command == "EXIT"|| command == "\0")
		{
			std::cout << "Ok time to go, bye!!" << std::endl;
			break;
		}
		else
		{
			std::cout << "Wrong command only accept: ADD, SEARCH or EXIT" << std::endl;
		}

	}
    return (0);
}