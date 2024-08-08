/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:00 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:44:21 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <cstdlib>
#include <sstream>

/**
 * @file main.cpp
 * 
 * This file contains the main function for a simple program that demonstrates dynamic polymorphism in C++ using an Animal hierarchy.
 * The program creates an array of Animal pointers, half of which are initialized to point to Cat objects and the other half to Dog
 * objects. This setup is used to illustrate how objects of derived classes (Cat and Dog) can be treated as objects of their base
 * class (Animal) through pointer polymorphism.
 * 
 * Key Components:
 * - Animal, Dog, and Cat classes: These classes form a hierarchy where Dog and Cat are derived from Animal.
 * - Brain class: An additional class that may be associated with the mental state of the Animals (not directly used in this excerpt).
 * 
 * Main Functionality:
 * 1. Initializes an array of Animal pointers, named AnimalFarm, with a fixed size of 4.
 * 2. Fills the first half of the array with Cat objects and the second half with Dog objects, demonstrating dynamic allocation and
 *    polymorphism.
 * 3. Waits for the user to press enter before proceeding to clean up.
 * 4. Deletes all dynamically allocated Animal objects in the array to prevent memory leaks.
 * 
 * Key Concepts Demonstrated:
 * - Dynamic Polymorphism: Using base class pointers to refer to derived class objects.
 * - Memory Management: Properly allocating and deallocating memory for objects in C++.
 * - Array Manipulation: Using arrays to manage multiple objects of different but related types.
 */
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
