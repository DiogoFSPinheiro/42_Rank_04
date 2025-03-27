/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/21 10:59:35 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixed_point = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "function getRawBits used" << std::endl;
	return this->_fixed_point;
}
	
void Fixed::setRawBits( int const raw )
{
	//std::cout << "function getRawBits used" << std::endl;
	this->_fixed_point = raw;
}

//-------------------------------------------------
	// ex01

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Assignment called" << std::endl;
	if (this != &other)
		this->_fixed_point = other._fixed_point; 
	return *this; 
	
}

Fixed::Fixed(int fixed_point)
{
	this->_fixed_point = fixed_point * (1 << _fracBits);
	//std::cout << "Int assign constructor called" << std::endl;
}

Fixed::Fixed(float fixed_point)
{
	this->_fixed_point = roundf(fixed_point * (1 << _fracBits));
	//std::cout << "Float assign constructor called" << std::endl;
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

//-------------------------------------------------
	// Comparors

bool Fixed::operator>(const Fixed& other) const {
    return this->_fixed_point > other._fixed_point;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_fixed_point < other._fixed_point;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_fixed_point >= other._fixed_point;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_fixed_point <= other._fixed_point;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_fixed_point == other._fixed_point;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_fixed_point != other._fixed_point;
}

//-------------------------------------------------

	// Arithmetic 
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const{
	Fixed returned;
	
	returned._fixed_point = (this->_fixed_point * other._fixed_point) >> this->_fracBits;
	
    return returned;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed returned;
	
    if (other._fixed_point == 0) {
        throw std::runtime_error("Division by zero");
    }
	returned._fixed_point = (this->_fixed_point << this->_fracBits) / other._fixed_point;
    return returned;
}


//-------------------------------------------------

	// Increment and decrement

Fixed& Fixed::operator++() {
    this->_fixed_point += 1;
    return *this;
}

Fixed& Fixed::operator--() {
    this->_fixed_point -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixed_point -= 1;
    return temp;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_fixed_point += 1;
    return temp;
}

//-------------------------------------------------

	// max - min

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
