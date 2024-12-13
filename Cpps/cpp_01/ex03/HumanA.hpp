/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:43 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 18:47:15 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP


#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA{

	private:
		std::string	_name;
		Weapon& 	_weapon;

    public:
		HumanA(const std::string name, Weapon& weapon);
		void	attack();
		
};

#endif