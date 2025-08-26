/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:09:06 by junjun            #+#    #+#             */
/*   Updated: 2025/08/26 23:36:41 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

//print all types
template <typename T>
void print(T const &x) {
	std::cout << x << "\n";
}

void intAdd(int &x) {
	x += 1;
}

//user defined type
struct newType
{
	char c;
};

std::ostream& operator<<(std::ostream& os, const newType& nt) {
	return os << "newType: " << nt.c;
}

void setChar(newType &nt) {
	nt.c++;
}

int main( void ) {

std::cout << "-----int array-----" << std::endl;
int intArray[] = {0, 1, 2, 3, 4};
iter(intArray, 5, intAdd);//non const function
iter(intArray, 5, print<int>);//const function

std::cout << "-----const int array-----\n";
int const ci[] = {10, 20, 30};
iter(ci, 3, print<int>);
// iter(ci, 3, intAdd);      //should not compile


std::cout << "----- const string array-----" << std::endl;
std::string const strArray[] = {"hello", "world", "42", "Heilbronn", "cpp", "07"};
iter(strArray, 6, print<std::string>);


std::cout << "-----user type array-----" << std::endl;
newType userArray[] = {{'a'}, {'b'}, {'c'}, {'d'}, {'e'}};
iter(userArray, 5, setChar);
iter(userArray, 5, print<newType>);

std::cout << "----- const user type array-----\n";
newType const cu[] = {{'x'},{'y'},{'z'}};
iter(cu, 3, print<newType>);
// iter(cu, 3, setChar);     // should not compile


std::cout << "-----empty array-----\n";
int empty[1] = {42};
iter(empty, 0, print<int>);  //nothing should be printed

return 0;
}
