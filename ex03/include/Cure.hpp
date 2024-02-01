/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:07:02 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 13:14:58 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure const & origin);
	~Cure(void);
	Cure& operator=(Cure const& origin);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};
#endif