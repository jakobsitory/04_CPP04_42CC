/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:51:24 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 13:00:02 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(Brain &brain) {
	*this = brain;
	std::cout << "Brain Copy Constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::operator= (const Brain& origin){
	std::cout << "Brain Assignment Operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = origin.ideas[i];
	return *this;
}