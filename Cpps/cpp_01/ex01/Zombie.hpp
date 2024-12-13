/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:23:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 16:51:12 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

#include <string>
#include <iostream>

class Zombie{

	private:
		std::string	_name;

    public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void	set_name(std::string name);
		void 	announce(void);		
};

Zombie* zombieHorde( int N, std::string name );





#endif