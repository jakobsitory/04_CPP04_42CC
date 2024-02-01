/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:01:11 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 12:58:05 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void){
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type){
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(Animal &animal){
	*this = animal;
	std::cout << "Animal Copy Constructor called" << std::endl;	
}

Animal::~Animal(){
	std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator= (const Animal& origin){
	std::cout << "Animal Assignment Operator called" << std::endl;
	this->type = origin.type;
	return *this;
}

std::string Animal::getType(void) const{
	return this->type;
}

void Animal::makeSound() const{
	std::cout << "sound" << std::endl;	
}