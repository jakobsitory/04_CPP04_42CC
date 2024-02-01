/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:09:11 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 12:49:25 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{

public:
	Dog(void);
	Dog(Dog &dog);
	~Dog(void);
	Dog& operator= (const Dog& origin);

	void makeSound(void) const;
};

#endif