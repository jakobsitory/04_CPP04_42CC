/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:28:56 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 16:51:45 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource Constructor Called" << std::endl;
	for (int i= 0; i < 4; i++)
		this->_source[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & origin){
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
	*this = origin;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource Destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_source[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource const& origin) {
	std::cout << "MateriaSource Assignment Operator Called" << std::endl;
	for (int i =0; i < 4; i++)
		this->_source[i] = origin._source[i];
	return *this;
}


void MateriaSource::learnMateria(AMateria* materia){
	int	i = 0;
	while (i < 4 && this->_source[i] != NULL)
		i++;
	if (i < 4){
		this->_source[i] = materia;
		std::cout << materia->getType() << " added to Materiasource" << std::endl;
		return ;
	}
	std::cout << "Nothing added to Materiasource" << std::endl;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	int	i = 0;
	while ( i < 4 && this->_source[i] && this->_source[i]->getType() != type)
		i++;
	if (i < 4 && this->_source[i] && this->_source[i]->getType() == type){
		std::cout << type << " created from Materiasource" << std::endl;
		return this->_source[i]->clone();
	}
	std::cout << type << " not available in Materiasource" << std::endl;
	return NULL;
}
