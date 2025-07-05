/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:51:11 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/05 18:02:14 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
j->makeSound();//Woof
i->makeSound(); //Meow
meta->makeSound();//Animal makes a sound
delete meta;
delete j;
delete i;

std::cout << "\n=== WrongAnimal test ===" << std::endl;
const WrongAnimal* wrong = new WrongCat();
std::cout << wrong->getType() << std::endl;
wrong->makeSound();// WrongAnimal makes a wrong sound
delete wrong;

return 0;
}