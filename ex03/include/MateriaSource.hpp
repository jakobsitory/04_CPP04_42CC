/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:38:48 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 13:14:44 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"

class AMateria; 

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_source[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const & origin);
	~MateriaSource();
	MateriaSource& operator=(MateriaSource const& origin);
	
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif