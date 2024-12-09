/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:23:04 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 16:49:27 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie_horde = new Zombie[N];
	int		i = 0;
	
	while (N > i)
	{
		zombie_horde[i].set_name(name);
		i++;
	}
	
	return zombie_horde;
}