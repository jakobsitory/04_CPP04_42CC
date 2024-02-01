/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:20:15 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 16:11:46 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void){
	std::cout << "AMateria Constructor Called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type){
	std::cout << "AMateria Constructor Called" << std::endl;
}


AMateria::AMateria(AMateria const & origin){
	std::cout << "AMateria Copy Constructor Called" << std::endl;
	*this = origin;
}

AMateria::~AMateria(void){
	std::cout << "AMateria Destructor Called" << std::endl;
}

AMateria& AMateria::operator=(AMateria const& origin){
	std::cout << "AMateria Assignment Operator Called" << std::endl;
	this->_type = origin._type;
	return *this;
}

std::string const & AMateria::getType() const{
	return this->_type;
}