/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:36:42 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:44:50 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

/**
 * @brief Demonstrates the use of a magic materia system in C++.
 * 
 * This excerpt showcases a simulation of a magic materia system, inspired by RPG mechanics, where characters can equip and use magical
 * materias. The system involves creating materias, learning them, equipping them to characters, and using them on other characters.
 * 
 * Key Components:
 * - IMateriaSource: An interface for a source of materias, responsible for learning and creating materias.
 * - MateriaSource: Concrete implementation of IMateriaSource, can learn and create specific materias like Ice and Cure.
 * - AMateria: Abstract class representing a generic materia, with methods for use.
 * - Ice, Cure: Concrete implementations of AMateria, representing specific types of materias.
 * - ICharacter: An interface for characters that can equip and use materias.
 * - Character: Concrete implementation of ICharacter, can equip materias and use them on other characters.
 * 
 * Main Functionality Demonstrated:
 * 1. Constructors: Demonstrates creating a materia source, learning materias, and creating a character.
 * 2. Create Materia: Shows how to create materias from the source and equip them to a character.
 * 3. Use on a New Character: Illustrates using equipped materias on another character, including handling of invalid slots.
 * 4. Deep Copy Character: Demonstrates deep copying a character along with their equipped materias.
 * 
 * This excerpt highlights object-oriented programming principles such as abstraction, encapsulation, and polymorphism. It also
 * demonstrates memory management through dynamic allocation and the importance of deep copying in C++.
 */
void ft_tests()
{
	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTORS:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	std::cout << std::endl;

	// Create Materia
	std::cout << "CREATE MATERIA:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	AMateria	*tmp;
	
	AMateria	*tmp1;
	AMateria	*tmp2;
	AMateria	*tmp3;
	// AMateria	*tmp4;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	tmp = src->createMateria("ice"); // null
	me->equip(tmp);
	std::cout << std::endl;

	// Use on a new character
	std::cout << "USE ON A NEW CHARACTER:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	me->use(2, *bob); // Use an empty / non existing slot in inventory
	me->use(-4, *bob);
	me->use(18, *bob);
	std::cout << std::endl;

	// Deep copy character
	std::cout << "DEEP COPY CHARACTER:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	Character	*charles = new Character("Charles");
	tmp2 = src->createMateria("cure");
	charles->equip(tmp2);
	tmp3 = src->createMateria("ice");
	charles->equip(tmp3);
	tmp = src->createMateria("fire");
	charles->equip(tmp);
	Character	*charles_copy = new Character(*charles);
	std::cout << std::endl;

	// Deep copy vs its source character
	std::cout << "DEEP COPY VS SOURCE:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	charles->unequip(0); // this shows that they have different materia pointers equipped
	// tmp4 = charles_copy->getMateriaFromInventory(1);
	charles_copy->unequip(0); //this will produce a leak if we don't store the address somewhere else before
	// delete tmp4;
	tmp = src->createMateria("cure");
	charles_copy->equip(tmp);
	tmp = src->createMateria("ice");
	charles_copy->equip(tmp);
	std::cout << std::endl;

	charles->use(0, *bob);
	charles->use(1, *bob);
	charles->use(2, *bob);
	charles->use(3, *bob);
	std::cout << std::endl;
	charles_copy->use(0, *bob);
	charles_copy->use(1, *bob);
	charles_copy->use(2, *bob);
	charles_copy->use(3, *bob);
	std::cout << std::endl;

	// Unequip tests:
	std::cout << "UNEQUIP:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	me->unequip(-1); // unequip an empty / non existing slot in inventory
	me->unequip(18);
	me->unequip(3);
	std::cout << std::endl;
	me->use(1, *charles);
	me->unequip(1); // Unequip a valid slot in inventory (cure unequipped)
	me->use(1, *charles); // try to use it
	std::cout << std::endl;

	// Destructors
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "\nDeleting bob" << std::endl;
	delete bob;
	std::cout << "\nDeleting me" << std::endl;
	delete me;
	std::cout << "\nDeleting src" << std::endl;
	delete src;
	std::cout << "\nDeleting charles" << std::endl;
	delete charles;
	std::cout << "\nDeleting charles" << std::endl;

	// std::cout << "\nDeleting charles_copy" << std::endl;
	delete charles_copy; //THIS PRODUCES ERRORS

	// delete tmp1;
	// delete tmp2;
	std::cout << std::endl;
	//system("leaks ex03");
}

void more_test(void) {
  std::cout << BLUE << "----- PDF Test: -----"
            << std::endl << std::endl;
	
	IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;

  std::cout << GREEN << std::endl
            << "----- Overfilling Character with Materias: -----" << std::endl
            << std::endl;
	
  	IMateriaSource* materia_source = new MateriaSource();
  	materia_source->learnMateria(new Cure());
  	ICharacter* alf = new Character("Alf");
  	for (int i = 0; i < 56; i++) {
    	alf->equip(materia_source->createMateria("cure"));
	}
	delete materia_source;
	delete alf;

	std::cout << YELLOW << std::endl
            << "----- Copy costructor and assignment operator shinenigans -----"
            << std::endl << std::endl;
	
	IMateriaSource* ms = new MateriaSource();
	AMateria *cure = new Cure();
	ms->learnMateria(cure);
	AMateria* temp_materia = ms->createMateria("cure");
	Character* bert = new Character("Bert");
	bert->equip(temp_materia);
	Character *casper = new Character(*bert);
	casper->use(0, *bert);
	casper->use(0, *bert);
	Character *dobby = new Character("Dobby");
	*dobby = *bert;
	dobby->use(0, *bert);
std::cout << "\ndeletin ms" <<std::endl;
	delete ms;
std::cout << "\ndeletin bert" <<std::endl;
	delete bert;
std::cout << "\ndeletin casper" <<std::endl;
	delete casper;
std::cout << "\ndeletin dobby" <<std::endl;
	delete dobby;
}

int main()
{
	ft_tests();
	// more_test();
	// Leaks check
	std::cout << "LEAKS:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	// system("leaks ex03");
	return (0);
}

/* 
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
std::cout << "deleted bob" <<std::endl;
	delete me;
std::cout << "deleted me" <<std::endl;
	delete src;
std::cout << "deleted sec" <<std::endl;
	return 0;
} 
*/