/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:32 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 21:30:56 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP


#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB{

	private:
		std::string	_name;
		Weapon*		_weapon;

    public:
		HumanB(const std::string name);
		HumanB(const std::string name, Weapon *weapon);
		void	setWeapon(Weapon& weapon);
		void	attack();
		
};


#endif