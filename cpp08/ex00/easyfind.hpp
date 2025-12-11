#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // for std::find
#include <stdexcept> //for exceptions

//non const
template <typename T>
typename T::iterator easyfind(T &container, int value) {
    //iter from begin to end
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}

//const
template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}

#endif // EASYFIND_HPP