/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:04:42 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 13:00:34 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;	
}

Dog::Dog(Dog &Dog){
	*this = Dog;
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator= (const Dog& origin){
	std::cout << "Dog Assignment Operator called" << std::endl;
	this->type = origin.type;
	this->_brain = origin._brain;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "WUFF" << std::endl;	
}