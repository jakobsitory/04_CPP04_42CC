/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:00 by jschott           #+#    #+#             */
/*   Updated: 2024/01/30 10:34:51 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <cstdlib>
#include <sstream>

int main(void)
{
	Animal*	AnimalFarm[4];
	int		len;

	len = (int) sizeof(AnimalFarm) / (int) sizeof(AnimalFarm[0]);
	for (int i = 0; i < .5 * len; i++)
		AnimalFarm[i] = new Cat();
	for (int i = .5 * len; i < len; i++)
		AnimalFarm[i] = new Dog();
	
	std::cout << std::endl << "Press enter to delete the Animals" << std::endl;
	std::string	enter;
	std::getline(std::cin, enter);
	for (int i = 0; i < len; i++)
		delete AnimalFarm[i];
	
	return 0;
}
