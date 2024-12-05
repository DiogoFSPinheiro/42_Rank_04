/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:45:18 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/05 18:31:13 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include "Contact.hpp"

class Phonebook{

	private:
		Contact contacts[8];
		int		current_contacts;

    public:
		Phonebook() : current_contacts(0) {}
		void	add_contact(int index);
		void	print_contacts();
		
};



#endif