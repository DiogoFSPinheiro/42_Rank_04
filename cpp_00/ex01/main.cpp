/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:22:21 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/05 18:28:53 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>

int main()
{
    Contact person;
	Phonebook PhoneBook;
	std::string command;
	int i;

	i = 0;
	while(43)
 	{
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			PhoneBook.add_contact(i);
			i++;
		}
		
		else if (command == "SEARCH")
		{
			PhoneBook.print_contacts();

		}
		
		else if (command == "\0" || command == "EXIT")
		{
			std::cout << "ok time to go, bye!!" << std::endl;
			break;
		}
			

		else
			std::cout << "Wrong command" << std::endl;


	}
    return 0;
}