/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:03:19 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 12:48:50 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat(void);
	Cat(Cat &cat);
	~Cat(void);
	Cat& operator= (const Cat& origin);

	void makeSound(void) const;
};

#endif