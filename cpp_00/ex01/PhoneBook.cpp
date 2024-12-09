/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:47:11 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 14:21:01 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>



int Phonebook::add_contact(int index)
{
	index = current_contacts % 8;
	
	std::string first_name;
	std::cout << "ADD First Name " ;
	std::getline(std::cin, first_name);
	if (check_field(first_name, 0) == true)
		return false;
	
	std::string last_name;
	std::cout << "ADD Last Name  " ;
	std::getline(std::cin, last_name);
	if (check_field(last_name, 0) == true)
		return false;
	
	std::string nickname;
	std::cout << "ADD Nickname   " ;
	std::getline(std::cin, nickname);
	if (check_field(nickname, 0) == true)
		return false;
	
	std::string darkest_secret;
	std::cout << "ADD Secret     " ;
	std::getline(std::cin, darkest_secret);
	if (check_field(darkest_secret,0) == true)
		return false;
	
	std::string number;
	std::cout << "ADD Number     " ;
	std::getline(std::cin, number);
	if (check_field(number, 1) == true)
		return false;
	
	contacts[index].fill_contact(first_name, last_name, nickname, darkest_secret, number, index);
	current_contacts++;
	return true;
}

bool Phonebook::check_field(std::string field, int nbr)
{
	
	unsigned long n = -1;
	while(nbr > 0 && field.size() > ++n)
	{
		if(!isdigit(field[n]))
		{
			std::cout << "A Phone Number mustn't have letters in it" << std::endl;
			return true;
		}
	}
	
	if (std::cin.eof() || std::cin.fail())
    {
		std::cin.clear();
        std::cout << "\nInput interrupted. Ending program..." << std::endl;
        return true;
    }
	
	if (field.find_first_not_of(' ') || field.find_first_not_of('	'))
	{
		std::cout << "You must fill all fields! Aborting..." << std::endl;
		return true;
	}
	
	return false;
}

bool Phonebook::print_contacts()
{
    int i = -1;
	if (current_contacts == 0)
	{
		std::cout << "No contacts yet in the PhoneBook" << std::endl;
		return false;
	}
		
	std::cout << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First Name" << " | "
              << std::setw(10) << "Last Name" << " | "
              << std::setw(10) << "Nickname" << std::endl;

    while (++i < current_contacts && i < 8)
    {
        std::cout << std::setw(10) << contacts[i].show_index() << " | "
                  << std::setw(10) << contacts[i].show_data("first_name") << " | "
                  << std::setw(10) << contacts[i].show_data("last_name") << " | "
                  << std::setw(10) << contacts[i].show_data("nickname") << std::endl;
				  
    }
	std::cout << std::endl;
	return true;

}


bool	Phonebook::print_single_contact(int index)
{
	if (index > 0 && index <= 8 && current_contacts >= index)
	{
		contacts[index-1].print_contactInfo();
		return true;
	}
	return false;
}

void	Phonebook::fill_contacts_tester()
{
	contacts[0].fill_contact("Alice", "Smith", "Ali", "Afraid of spiders", "1234567890", 0);
	contacts[1].fill_contact("Bob", "Johnson", "Bobby", "Lost a sock once", "2345678901", 1);
	contacts[2].fill_contact("Charlie", "Brown", "Chuck", "Secretly a ninja", "3456789012", 2);
	contacts[3].fill_contact("Diana", "Prince", "Wonder", "Loves ice cream", "4567890123", 3);
	contacts[4].fill_contact("Eve", "Taylor", "Evie", "Sings in the shower", "5678901234", 4);
	contacts[5].fill_contact("Frank", "Castle", "Punisher", "Knits sweaters", "6789012345", 5);
	contacts[6].fill_contact("Grace", "Hopper", "Amazing", "Collects stamps", "7890123456", 6);
	contacts[7].fill_contact("Hank", "Pym", "Ant-Man", "Fears clowns", "8901234567", 7);	
	current_contacts = 8;
}