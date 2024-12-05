/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:47:11 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/05 18:31:20 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstddef>

void Phonebook::add_contact(int index)
{

	std::string first_name;
	std::cout << "ADD First Name " ;
	std::getline(std::cin, first_name);
	std::string last_name;
	std::cout << "ADD Last Name  " ;
	std::getline(std::cin, last_name);
	std::string nickname;
	std::cout << "ADD nick Name  " ;
	std::getline(std::cin, nickname);
	std::string darkest_secret;
	std::cout << "ADD Secret     " ;
	std::getline(std::cin, darkest_secret);
	std::string number;
	std::cout << "ADD Number     " ;
	std::getline(std::cin, number);
	contacts[index].fill_contact(first_name, last_name, nickname, darkest_secret, number, index);
	current_contacts++;

}

void	Phonebook::print_contacts()
{
	int i = -1;
	while (++i < current_contacts)
	{
		std::cout << "Index      :" << contacts[i].show_index() << " | ";
		std::cout << "First Name :" << contacts[i].show_data("first_name") << " | ";
		std::cout << "Last Name  :" << contacts[i].show_data("last_name")<< " | ";
		std::cout << "NickName   :" << contacts[i].show_data("nickname") << std::endl;
	}
}