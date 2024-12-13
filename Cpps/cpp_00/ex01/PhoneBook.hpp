/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:45:18 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 12:12:03 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include <iomanip>
#include <limits.h>
#include <string>
#include <cstdlib>


#include "Contact.hpp"

class Phonebook{

	private:
		Contact contacts[8];
		int		current_contacts;

    public:
		Phonebook() : current_contacts(0) {}
		int		add_contact(int index);
		bool	print_contacts();
		bool	print_single_contact(int index);
		void	fill_contacts_tester();
		bool	check_field(std::string field, int nbr);
		
};



#endif