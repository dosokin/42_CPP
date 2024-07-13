#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <algorithm>

template<typename T>
typename T::const_iterator easyfind(const T& container, int i);

#endif