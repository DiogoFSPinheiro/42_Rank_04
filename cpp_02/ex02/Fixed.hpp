/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:23:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/09 16:15:15 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

#include <string>
#include <iostream>
#include <cmath>

class Fixed{

	private:
		int _fixed_point;
		static const int _fracBits = 8;

    public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(int fixed_point);
		Fixed(float fixed_point);
		~Fixed();
		Fixed& operator=(const Fixed& other);

		int getRawBits(void )const;
		void setRawBits(int const raw);

		int toInt(void) const;
		float toFloat(void) const;

		// Comparors
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Arithmetic 
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Increment and decrement
		Fixed& operator++(); // pre
		Fixed& operator--(); // pre
		Fixed operator++(int); // post
		Fixed operator--(int); // post

		// max - min
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);



};

std::ostream& operator<<(std::ostream& output, const Fixed& other);


#endif