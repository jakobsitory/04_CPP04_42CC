/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:07:02 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 13:14:51 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP


#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const & origin);
	~Ice(void);
	Ice& operator=(Ice const& origin);

	AMateria*	clone() const;
	void 		use(ICharacter& target);
};

#endif
