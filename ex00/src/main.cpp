/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:00 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:43:51 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <string>
#include <cstdlib>
#include <sstream>

/**
 * @file main.cpp
 * 
 * Demonstrates polymorphism in C++ through the use of Animal, Dog, Cat, WrongAnimal, and WrongCat classes. The program creates instances
 * of these classes and calls their respective makeSound() methods to illustrate the concept of virtual functions and how C++ handles
 * polymorphism and inheritance.
 * 
 * Key Concepts Demonstrated:
 * - Polymorphism: The ability of different classes to be treated as instances of the same class through inheritance.
 * - Virtual Functions: Functions in a base class that can be overridden in derived classes.
 * - Dynamic Memory Allocation: Using new to create objects on the heap and delete to free them.
 * 
 * The program is divided into two parts:
 * 1. The first part creates instances of Animal, Dog, and Cat. It demonstrates polymorphism by treating Dog and Cat objects as Animal
 *    and calling their makeSound() method, which is a virtual function overridden in both Dog and Cat classes.
 * 2. After user input, the second part creates instances of WrongAnimal and WrongCat to show what happens when the makeSound() method
 *    is not virtual. It illustrates how the lack of virtual functions prevents polymorphism from working as expected.
 * 
 * Cleanup:
 * - The program properly deletes all dynamically allocated objects to prevent memory leaks.
 * 
 * Note:
 * - The program contains a bug in the second part where it attempts to delete `i` and `meta` again, which were already deleted in the
 *   first part. This can lead to undefined behavior.
 */
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
