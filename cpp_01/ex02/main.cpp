/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 17:41:22 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ostream>
#include <string>
#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	std::cout << "The memory address of the string variable	" << &string << std::endl
			  << "The memory address held by stringPTR     	" << stringPTR << std::endl
			  << "The memory address held by stringREF     	" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable	        " << string << std::endl
			  << "The value held by stringPTR     	        " << *stringPTR << std::endl
			  << "The value held by stringREF     	        " << stringREF << std::endl;
	return 0;
}