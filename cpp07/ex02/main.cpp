/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 00:23:53 by junjun            #+#    #+#             */
/*   Updated: 2025/08/28 17:01:46 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

static void printHeader(const char* title) {
    std::cout << "==== " << title << " ====\n";
}

int main() {
    printHeader("default-constructed empty array");
    Array<int> a0;
    std::cout << "a0.size() = " << a0.size() << "\n";
    try {
        // a0[0]; // should throw
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << "\n";
    }
    std::cout << "\n";

    printHeader("int array with default initialization (zeros)");
    Array<int> ai(5);
    std::cout << "ai.size() = " << ai.size() << "\n";
    for (size_t i = 0; i < ai.size(); ++i) std::cout << ai[i] << " ";
    std::cout << "\n";
    // change values
    for (size_t i = 0; i < ai.size(); ++i) ai[i] = static_cast<int>(i + 1);
    for (size_t i = 0; i < ai.size(); ++i) std::cout << ai[i] << " ";
    std::cout << "\n";

    printHeader("std::string array default initialization (empty strings)");
    Array<std::string> as(3);
    for (size_t i = 0; i < as.size(); ++i) std::cout << '"' << as[i] << "\" ";
    std::cout << "\n";
    as[0] = "hello"; as[1] = "array"; as[2] = "template";
    for (size_t i = 0; i < as.size(); ++i) std::cout << as[i] << " ";
    std::cout << "\n";

    printHeader("copy-construct");
    Array<std::string> asCopy(as);
    asCopy[1] = "WORLD";
    std::cout << "as    : "; 
	for (size_t i = 0; i < as.size(); ++i) std::cout << as[i] << " ";
    std::cout << "\nasCopy: "; 
	for (size_t i = 0; i < asCopy.size(); ++i) std::cout << asCopy[i] << " ";
    std::cout << "\n";

    printHeader("assignment");
    Array<std::string> asAssign(2);
    asAssign = as;
    asAssign[0] = "BYE";
    std::cout << "as      : "; 
	for (size_t i = 0; i < as.size(); ++i) std::cout << as[i] << " ";
    std::cout << "\nasAssign: "; 
	for (size_t i = 0; i < asAssign.size(); ++i) std::cout << asAssign[i] << " ";
    std::cout << "\n";

	
    printHeader("out of bounds");
    try {
        std::cout << ai[999] << "\n";
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << "\n";
    }
    try {
        const Array<int>& cai = ai;
        std::cout << cai[5] << "\n";
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << "\n";
    }
    std::cout << "\n";

    printHeader("size function test");
    const Array<int> ca(3);
    std::cout << "ca.size() = " << ca.size() << "\n";
    try {
        std::cout << ca[0] << "\n"; // default initialized to 0
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << "\n";
    }

    return 0;
}

// ----- from subject

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }