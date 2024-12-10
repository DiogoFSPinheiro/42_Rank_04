/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 19:05:31 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int fixed_point)
{
	this->_fixed_point = fixed_point * (1 << _fracBits);
	std::cout << "Int assign constructor called" << std::endl;
}

Fixed::Fixed(float fixed_point)
{
	this->_fixed_point = fixed_point * (1 << _fracBits);
	std::cout << "Int assign constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Assignment called" << std::endl;
	if (this != &other)
		this->_fixed_point = other._fixed_point; // Copy the raw value from 'other' to the current object
	return *this; // Return the current object (this) by reference to support chaining a = b  =c
	
}

