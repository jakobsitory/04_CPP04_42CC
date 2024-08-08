/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:00 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:45:18 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <cstdlib>
#include <sstream>

/**
 * @brief Main function demonstrating dynamic polymorphism with an Animal hierarchy.
 * 
 * This program creates an array named AnimalFarm, which is populated with Cat and Dog objects to demonstrate dynamic polymorphism.
 * The array is evenly split between Cat and Dog objects, showcasing how derived class objects can be treated as base class objects.
 * After creation, the program waits for user input before deleting all dynamically allocated objects to prevent memory leaks.
 * 
 * Detailed Steps:
 * 1. Calculates the length of the AnimalFarm array to determine how many Cat and Dog objects to create.
 * 2. Fills the first half of the AnimalFarm array with dynamically allocated Cat objects.
 * 3. Fills the second half of the AnimalFarm array with dynamically allocated Dog objects.
 * 4. Waits for the user to press enter by reading a line from standard input.
 * 5. Iterates over the AnimalFarm array, deleting all dynamically allocated Animal objects to clean up allocated memory.
 * 
 * Note: The commented-out line for creating a TestAnimal object of type Animal is left intentionally to demonstrate that the Animal
 * class is designed to be an abstract base class and should not be instantiated directly.
 * 
 * @return int Returns 0 upon successful execution.
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
	//Animal* TestAnimal = new Animal();
	
	std::cout << std::endl << "Press enter to delete the Animals" << std::endl;
	std::string	enter;
	std::getline(std::cin, enter);
	for (int i = 0; i < len; i++)
		delete AnimalFarm[i];
	
	return 0;
}
