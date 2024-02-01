/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:03:19 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 12:49:49 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat(void);
	WrongCat(WrongCat &cat);
	~WrongCat(void);
	WrongCat& operator= (const WrongCat& origin);

	void makeSound(void) const;
};

#endif