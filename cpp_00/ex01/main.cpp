/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:22:21 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 11:56:00 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdio>
#include <string>
#include <cstdlib>

int main()
{
    Contact person;
	Phonebook PhoneBook;
	std::string command;

	//PhoneBook.fill_contacts_tester();
	int i = 0;
	std::cout << "Welcome to my PhoneBook!!" << std::endl;
	while(43)
 	{
		std::cout << "Use: ADD, SEARCH or EXIT" << std::endl << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			if(PhoneBook.add_contact(i) == true)
				i++;
		}
		else if (command == "SEARCH")
		{
			if(PhoneBook.print_contacts() == true)
			{
				std::cout << "Choose index number: " ;
				std::getline(std::cin, command);
				unsigned long n = -1;
				int	ok = 1;
				while(command.size() > ++n)
				{
					if(!isdigit(command[n]))
					{
						std::cout << "Wrong index number" << std::endl;
						ok = 0;
						break ;
					}
				}
				if (ok == 1)
				{
					int index = std::atoi(command.c_str());
					if (PhoneBook.print_single_contact(index) == false)
						std::cout << "Wrong index number" << std::endl;
				}
			}
		}
		else if (command == "EXIT"|| std::cin.eof())
		{
			std::cout << "Ok time to go, bye!!" << std::endl;
			break;
		}
		else
			std::cout << "Wrong command only accept: ADD, SEARCH or EXIT" << std::endl;
	}
    return (0);
}
