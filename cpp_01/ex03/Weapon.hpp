/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:48 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 18:37:49 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP


#include <string>
#include <iostream>

class Weapon{

	private:
		std::string	_type;

    public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		std::string& getType();
		void		setType(std::string type);

};



#endif