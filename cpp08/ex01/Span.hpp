#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>


class Span {
private:
    unsigned int maxSize;
    std::vector<int> numbers;
public:
    Span(unsigned int n);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);


    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
};

#endif