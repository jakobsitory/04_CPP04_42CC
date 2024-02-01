/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:56:26 by jschott           #+#    #+#             */
/*   Updated: 2024/02/01 12:01:58 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class AMateria; 

class Character : public ICharacter
{
private:
	static AMateria**	floor_;
	static int			floor_size_;
	static int			character_count_;
	
public:
	Character(std::string name);
	Character(Character const & origin);
	~Character();
	Character& operator=(Character const& origin);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void drop(AMateria &materia);
};

#endif