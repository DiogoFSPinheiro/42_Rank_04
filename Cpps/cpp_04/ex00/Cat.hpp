/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:23:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/18 18:42:21 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP


#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat : public Animal
{

    public:
		Cat();
		Cat(const Cat& other);
		Cat &operator=(const Cat& other);
		virtual ~Cat();
		
		virtual void makeSound() const;
};






#endif