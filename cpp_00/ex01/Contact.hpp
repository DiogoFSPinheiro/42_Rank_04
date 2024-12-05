/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:22:14 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/05 18:05:30 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <cctype>


class Contact{

	private:
		int index;
        std::string number;
		std::string first_name; 
		std::string last_name;
		std::string nickname;
        std::string darkest_secret;

    public:
        void		print_contactInfo();
		std::string	show_data(std::string name);
		void		fill_contact(std::string fname, std::string lname, std::string nname, std::string secret, std::string nbr, int i);
		int			show_index();
};

#endif