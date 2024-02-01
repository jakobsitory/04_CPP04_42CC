/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:50:20 by jschott           #+#    #+#             */
/*   Updated: 2024/02/01 09:36:44 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice Constructor Called" << std::endl;
}

Ice& Ice::operator=(Ice const& origin){
	std::cout << "Ice Assignment Operator Called" << std::endl;
	this->_type = origin._type;
	return *this;	
}

Ice::~Ice(){
	std::cout << "Ice Destructor Called" << std::endl;
}

AMateria* Ice::clone() const{
	std::cout << this->getType() << " gets cloned" << std::endl;
	AMateria* clone = new Ice();
	return clone;
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}