/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:43 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 12:49:33 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
	
public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal &animal);
	~WrongAnimal();
	WrongAnimal& operator= (const WrongAnimal& origin);

	virtual void	makeSound() const;
	std::string		getType(void) const;
};

#endif