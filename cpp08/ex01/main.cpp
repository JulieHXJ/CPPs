#include "Span.hpp"
#include <iostream>


// Test your Span with at least 10,000 numbers.
int main()
{
    //given test
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;

std::cout << "\n=== Exception tests ===" << std::endl;

    Span sp1(3);

    // Not enough numbers
    try {
        sp1.addNumber(42);
        std::cout << sp1.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    // Overfilling
    try {
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(3);
    } catch (const std::exception &e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }



	std::cout << "\n=== Large test with 10,000 numbers ===" << std::endl;

    const int N = 10000;
    Span sp2(N);

    // Fill with 0, 2, 4, 6, ... 19998
    for (int i = 0; i < N; ++i)
    {
        sp2.addNumber(i * 2);
    }

    try {
        int shortest = sp2.shortestSpan();
        int longest  = sp2.longestSpan();
        std::cout << "Shortest span:   " << shortest << std::endl;
        std::cout << "Longest span:    " << longest << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception in large test: " << e.what() << std::endl;
    }

}