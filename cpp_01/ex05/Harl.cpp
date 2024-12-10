/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:45 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 10:51:42 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

void	Harl::debug(void)
{
	std::cout << "[DEBUG]   " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "[INFO]    " << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[WARNING] " << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ERROR]   " <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void(Harl::*options[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,};
	std::string levels[] = {"DEBUG","INFO","WARNING","ERROR"};

	int		c = 0;
	while (c < 4)
	{
		if (levels[c] == level)
		{
			(this->*options[c])();
			return ;
		}
		c++;
	}
	std::cout << "[WHUT?]   " << "I can't speak like this!!!!" << std::endl;
	return ; 
}

Harl::Harl()
{
}

Harl::~Harl()
{
}