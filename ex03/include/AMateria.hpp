/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:01:05 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 13:16:56 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

class ICharacter; 

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const & origin);
	virtual ~AMateria(void);
	AMateria& operator=(AMateria const& origin);

	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
};

#endif