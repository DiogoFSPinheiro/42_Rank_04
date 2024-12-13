/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/13 11:30:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void )
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl << std::endl;
		std::cout << "max is" << Fixed::max(a, b) << std::endl;
		std::cout << "min is" << Fixed::min(a, b) << std::endl;
	}
	std::cout << std::endl;
	//my testrinos
	{
		Fixed a(22);
		Fixed b(2);
		Fixed h(a);
		if (a != b)
			std::cout << "dif" << std::endl;
		if (a == h)
			std::cout << "same" << std::endl;
	}
	std::cout << std::endl;
	{
		Fixed a(22 / 2);
		Fixed b(2 + 2);
		Fixed c(2 - 2);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	std::cout << std::endl;
	{
		Fixed a(22 >= 2);
		Fixed b(2 < 2);
		Fixed c(2 > 2);
		Fixed f;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		a = a / 0;
	}
	std::cout << std::endl;
	return 0;
}