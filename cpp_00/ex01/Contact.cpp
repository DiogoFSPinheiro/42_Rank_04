/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:22:17 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/05 14:43:19 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::print_contactInfo()
{
	std::cout << "First Name     " << first_name << std::endl;
	std::cout << "Last Name      " << last_name << std::endl;
	std::cout << "Phone Number   " << number << std::endl;
	std::cout << "Nick Name      " << nickname << std::endl;
	std::cout << "Darkest Secret " << darkest_secret << std::endl;

}

void Contact::fill_contact(std::string fname, std::string lname, std::string nname, std::string secret, std::string nbr, int i)
{
	first_name = fname;
	last_name = lname;
	nickname = nname;
	darkest_secret = secret;
	number = nbr;
	index = i + 1;
}

std::string	Contact::show_data(std::string name)
{
    if (name == "first_name")
	{
        if (first_name.length() > 10)
            return first_name.substr(0, 9) + '.';
        else
            return first_name;
    }else if (name == "last_name")
	{
        if (last_name.length() > 10)
            return last_name.substr(0, 9) + '.';
        else
            return last_name;
    }else if (name == "nickname")
	{
        if (nickname.length() > 10)
            return nickname.substr(0, 9) + '.';
        else
            return nickname;
    }else if (name == "secret"){
        return darkest_secret;
	}else if (name == "nbr"){
        return number;
	}else 
        return "not found";

}

int	Contact::show_index()
{
	return index;
}