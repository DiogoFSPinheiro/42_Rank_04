/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 18:42:24 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>
#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"

int	main(void)
{
	Weapon bonk;
	
	HumanA Bob = HumanA("Bob", bonk);
	
	Bob.attack();

	return 0;
}