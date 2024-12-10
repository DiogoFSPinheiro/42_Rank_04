/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:48:43 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 10:20:29 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP


#include <string>
#include <iostream>

class Harl{

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

    public:
		Harl();
		~Harl();
		void complain(std::string level);

};

#endif