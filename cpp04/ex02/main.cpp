/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:51:11 by xhuang            #+#    #+#             */
/*   Updated: 2025/07/09 11:27:12 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    // delete meta;
    delete j;
    delete i;

std::cout << "\n=== Additional test ===" << std::endl;

const int size = 10;// an array of Animal objects
Animal* zoo[size];

for (int i = 0; i < size; ++i) {
    if (i < size / 2)
        zoo[i] = new Dog();
    else
        zoo[i] = new Cat();
}

std::cout << "\n[ memory leak ]\n";
for (int i = 0; i < size; ++i) {
    delete zoo[i];  
}

std::cout << "\n[ deep copy test ]\n";
Dog cooper;
cooper.makeSound();
cooper.getBrain()->setIdea(0, "I love mama");

Dog copy = cooper;
copy.getBrain()->setIdea(0, "I hate vagetables");

std::cout << "Cooper's idea: " << cooper.getBrain()->getIdea(0) << std::endl;
std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl;


return 0;
}