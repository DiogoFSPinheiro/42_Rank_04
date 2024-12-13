/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/11 12:10:18 by diogosan         ###   ########.fr       */
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
	this->_fixed_point = roundf(fixed_point * (1 << _fracBits));
	std::cout << "Float assign constructor called" << std::endl;
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
		this->_fixed_point = other._fixed_point; 
	return *this; 
	
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixed_point / (1 << _fracBits);
}


int Fixed::toInt(void) const
{
    return this->_fixed_point / (1 << _fracBits);
}

std::ostream& operator<<(std::ostream& output, const Fixed& other)
{
	output << other.toFloat();
	return output;
}