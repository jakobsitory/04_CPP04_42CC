/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:01:11 by jschott           #+#    #+#             */
/*   Updated: 2024/01/29 17:07:34 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type){
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &WrongAnimal){
	*this = WrongAnimal;
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;	
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& origin){
	std::cout << "WrongAnimal Assignment Operator called" << std::endl;
	this->type = origin.type;
	return *this;
}

std::string WrongAnimal::getType(void) const{
	return this->type;
}

void WrongAnimal::makeSound() const{
	std::cout << "wrong sound" << std::endl;
}