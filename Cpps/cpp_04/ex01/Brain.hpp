/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/19 14:14:01 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain 
{
	protected:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain &operator=(const Brain& other);
		virtual  ~Brain();

		void		setIdeas(unsigned int index, std::string idea);
		std::string	getIdeas(unsigned int index) const;
		void		fillIdeas();

};






#endif