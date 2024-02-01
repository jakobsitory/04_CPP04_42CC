/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:31:23 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 17:09:44 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::~ICharacter(){
	std::cout << "ICharacter Destructor Called" << std::endl;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}
