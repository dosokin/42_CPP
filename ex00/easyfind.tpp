
#include "easyfind.hpp"

template<typename T>
typename T::const_iterator easyfind(const T& container, int i)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), i);

    if (it != container.end())
        return it;
    throw std::logic_error("element not found");
}