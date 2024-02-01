/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:26:26 by jschott           #+#    #+#             */
/*   Updated: 2024/01/31 12:50:11 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
	std::string	ideas[100];

public:
	Brain();
	Brain(Brain &brain);
	~Brain();
	Brain& operator= (const Brain& origin);
};

#endif