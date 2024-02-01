/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:50:20 by jschott           #+#    #+#             */
/*   Updated: 2024/02/01 09:36:48 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
	std::cout << "Cure Constructor Called" << std::endl;
}

Cure::Cure(Cure const & origin){
	std::cout << "Cure Copy Constructor Called" << std::endl;
	*this = origin;
}

Cure::~Cure(void){
	std::cout << "Cure Destructor Called" << std::endl;
}

Cure& Cure::operator=(Cure const& origin){
	std::cout << "Cure Assignment Operator Called" << std::endl;
	this->_type = origin._type;
	return *this;	
}

AMateria* Cure::clone() const{
	std::cout << this->getType() << " gets cloned" << std::endl;
	AMateria* clone = new Cure(*this);
	return clone;
}

void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}