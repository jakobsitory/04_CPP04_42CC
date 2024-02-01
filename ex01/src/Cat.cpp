/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:04:42 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 12:57:36 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destructor called" << std::endl;	
}

Cat& Cat::operator= (const Cat& origin){
	std::cout << "Cat Assignment Operator called" << std::endl;
	this->type = origin.type;
	this->_brain = origin._brain;
	return *this;
}

Cat::Cat(Cat &cat){
	*this = cat;
	std::cout << "Cat Copy Constructor called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "MEOW" << std::endl;	
}