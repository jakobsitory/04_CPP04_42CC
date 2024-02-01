/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:04:42 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 13:01:51 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;	
}

WrongCat& WrongCat::operator= (const WrongCat& origin){
	std::cout << "WrongCat Assignment Operator called" << std::endl;
	this->type = origin.type;
	return *this;
}

WrongCat::WrongCat(WrongCat &WrongCat){
	*this = WrongCat;
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Wrong MEOW" << std::endl;	
}