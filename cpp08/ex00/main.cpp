#include <vector>
#include <list>
#include <iostream>

#include "easyfind.hpp"

int main() {
    // (void)ac;
    // (void)av;

    // Test with std::vector
    std::cout << "=== Testing std::vector<int> ===" << std::endl;
    // std::vector<int> vec = {1, 2, 3, 4, 5};// not for c++98
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }   

    try {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }  

    // test with std::list
    std::cout << "\n=== Testing std::list<int> ===" << std::endl;
    // std::list<int> lst = {10, 20, 30, 40, 50}; // not for c++98
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    try {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }   

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
