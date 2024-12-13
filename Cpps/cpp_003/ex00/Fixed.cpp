/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 18:24:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "Assigment called" << std::endl;
	if (this != &other)
		this->_fixed_point = other.getRawBits(); // Copy the raw value from 'other' to the current object
	return *this; // Return the current object (this) by reference to support chaining a = b  =c
	
}

int Fixed::getRawBits( void ) const
{
	std::cout << "function getRawBits used" << std::endl;
	return this->_fixed_point;
}
		
		
void Fixed::setRawBits( int const raw )
{
	std::cout << "function getRawBits used" << std::endl;
	this->_fixed_point = raw;
}