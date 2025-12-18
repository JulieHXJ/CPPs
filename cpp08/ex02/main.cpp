#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <stack>

// If you run it a first time with your MutantStack, and a second time replacing the
// MutantStack with, for example, a std::list, the two outputs should be the same. Of
// course, when testing another container, update the code below with the corresponding
// member functions (push() can become push_back()).

int main()
{
    //run it once with MutantStack, once with std::list to compare output
    std::cout << "=== MutantStack output (given test) ===" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;//17
    mstack.pop();//remove 17

    std::cout << mstack.size() << std::endl;//size = 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;//testing iterator

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    // void(s);


    std::cout << "=== std::list output (reference) ===" << std::endl;
     std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;
    lst.pop_back();

    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator itl = lst.begin();
    std::list<int>::iterator itel = lst.end();

    ++itl;
    --itl;

    while (itl != itel)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }
    return 0;
}