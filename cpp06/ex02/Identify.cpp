/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:21:10 by junjun            #+#    #+#             */
/*   Updated: 2025/08/24 18:50:59 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time

Base* generate(void){
	static bool seeded=false;
    if(!seeded)
	{ 
		std::srand(static_cast<unsigned>(std::time(0))); 
		seeded=true; 
	}
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "\033[32mGenerated A\n\033[0m";
			return new A();
		case 1:
			std::cout << "\033[33mGenerated B\n\033[0m";
			return new B();
		case 2:
			std::cout << "\033[34mGenerated C\n\033[0m";
			return new C();
		default:
			return NULL; // should never reach here
	}
}
void identify(Base* p){
	if (!p)
	{
		std::cout << "Null pointer\n";
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C\n";
	else
		std::cout << "Unknown type\n";
}

void identify(Base& p){
	try
	{
		(void)dynamic_cast<A&>(p);//unused variable
		std::cout << "Identified A\n";
		return;
	} catch(...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identified B\n";
		return;
	} catch(...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identified C\n";
		return;
	} catch(...) {}
	std::cout << "Unknown type\n";
}

//test program
int main(){

	for (int i = 0; i < 5; i++)
	{
		Base* base = generate();
		std::cout << "ptr test: ";
		identify(base);

		std::cout << "ref test: ";
		identify(*base);
		
		delete base;
	}
	return 0;
}
