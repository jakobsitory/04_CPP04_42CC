/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:00 by jschott           #+#    #+#             */
/*   Updated: 2024/01/29 17:25:20 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <string>
#include <cstdlib>
#include <sstream>

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete j;
	delete i;
	delete meta;
	
	std::cout << std::endl << "Press enter to rerun with WrongCats" << std::endl;
	std::string	enter;
	std::getline(std::cin, enter);
	
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();

	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound(); //will output the cat sound!
	wrong_meta->makeSound();
	delete i;
	delete meta;

	return 0;
}
