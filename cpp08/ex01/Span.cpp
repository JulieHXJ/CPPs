#include "Span.hpp"

Span::Span(unsigned int n){
    maxSize = n;
}

Span::~Span(){

}
Span::Span(const Span &other){
    maxSize = other.maxSize;
    numbers = other.numbers;
}

Span &Span::operator=(const Span &other){
    if (this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

void Span::addNumber(int num) {
    if (numbers.size() >= maxSize) {
        throw std::runtime_error("Span is already full");
    }
    numbers.push_back(num);
}

int Span::shortestSpan() const{
    if (numbers.size() < 2)
    {
        throw std::runtime_error("Not enough numbers to find a span");
    }
    // first sort, then calculate the neighbors
    std::vector<int> temp = numbers;
    std::sort(temp.begin(), temp.end());
    int shortest = temp[1] - temp[0];
    //iter through vector
    for (std::vector<int>::const_iterator it = temp.begin() + 1; it != temp.end(); ++it)
    {
        int diff = *it - *(it - 1);
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}
    
int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }
    //using iterator
    std::vector<int>::const_iterator minIt  = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator maxIt  = std::max_element(numbers.begin(), numbers.end());
    return *maxIt - *minIt;
}