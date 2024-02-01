/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:43 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 12:48:25 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string	type;
	
public:
	Animal(void);
	Animal(std::string type);
	Animal(Animal &animal);
	virtual ~Animal();
	Animal& operator= (const Animal& origin);

	virtual void	makeSound() const;
	std::string		getType(void) const;
};

#endif