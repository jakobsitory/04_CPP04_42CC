/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:53:49 by jschott           #+#    #+#             */
/*   Updated: 2024/02/01 12:51:57 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <vector>

AMateria** Character::floor_ = new AMateria*[1];
int Character::floor_size_ = 0;
int Character::character_count_ = 0;

void Character::drop(AMateria &materia){
	AMateria** new_floor = new AMateria*[floor_size_ + 1];
	for (int i = 0; i < floor_size_; i++)
		new_floor[i] = floor_[i];
	new_floor[floor_size_] = &materia;
	++floor_size_;
	delete[] floor_;
	floor_ = new_floor;
	
}

Character::Character(std::string name){
	character_count_++;
	std::cout << "Character Constructor Called: " << character_count_ << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & origin){
	character_count_++;
	std::cout << "Character Copy Constructor Called: " << character_count_ << std::endl;
	*this = origin;
}

Character::~Character(){
	character_count_--;
	std::cout << "Character Destructor Called: " << character_count_ << std::endl;
	if (character_count_ == 0 && floor_)
	{
		std::cout << std::endl << "ALL CHARACTERS ARE DEAD" << std::endl;
		for (int i = 0; i < floor_size_; i++){
			delete floor_[i];
		}
		delete[] floor_;
		floor_ = NULL;
		std::cout << "Floor is clean!" << std::endl << std::endl << std::endl;
	}
}

Character& Character::operator=(Character const& origin){
	std::cout << "Character Assignment Operator Called" << std::endl;
	this->_name = origin._name;
	for (int i =0; i < 4; i++){
		if (origin._inventory[i] != NULL)
			this->_inventory[i] = origin._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return *this;
}

std::string const & Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria* m){
	if (m == NULL){
		std::cout << this->getName() << " can't equip nonexistant AMateria" << std::endl;
		return ;
	}
	std::cout << this->getName() << " equips " << m->getType() << std::endl;
	int	i = 0;
	while ( i < 4 && this->_inventory[i] != 0)
		i++;
	if (i < 4)
		this->_inventory[i] = m;
	else
		drop(*m);
	return ;
}

void Character::unequip(int idx){
	if (idx < 0 || idx > 4)
		return ;
	std::cout << this->getName() << " unequips ";
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		std::cout << this->_inventory[idx]->getType() << std::endl;
	else
		std::cout << "nothing"<< std::endl;
	if (idx >= 0 && idx < 4)
	{
		std::cout << "Materia dropped to the floor"<< std::endl;
		drop(*this->_inventory[idx]);
		this->_inventory[idx] = NULL;
	}
	return ;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 4)
		return ;
	std::cout << this->getName() << " uses ";
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		std::cout << this->_inventory[idx]->getType() << " on " << target.getName();
	std::cout << std::endl;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	return ;
		
}
