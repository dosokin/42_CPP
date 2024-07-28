#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <queue>
#include <cmath>
#include <sstream>
#include <algorithm>


#define UNSET -1
#define MAX_INT 2147483647

enum printType{
    BEFORE,
    AFTER,
};

int                 safe_atoi(std::string s);
std::vector<int> vectorSort(int argc, char **argv);
std::deque<int> dequeSort(int argc, char **argv);



template<typename T>
T& extractInts(T& container, int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg.empty())
            throw std::logic_error("empty argument");
        if (arg.size() > 10)
            throw std::logic_error("int overflow");
        size_t pos = arg.find_last_of('-');
        if (pos != std::string::npos && pos != 0)
            throw std::logic_error("invalid characters in argument");
        if (pos == 0 && arg.size() > 1 && isdigit(arg.at(1)))
            throw std::logic_error("negative numbers not allowed");
        if (arg.find_first_not_of("0123456789") != std::string::npos)
            throw std::logic_error("invalid characters in argument");
        container.push_back(safe_atoi(arg));
    }
    return (container);
}

template<typename T>
void printContainer(const T& v)
{
    for (typename T::const_iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void printElement(const T& container, printType type){
    if (type == BEFORE)
        std::cout << "Before: ";
    else if (type == AFTER)
        std::cout << "After: ";
    printContainer(container);
    std::cout << std::endl;
}

template <typename Ti, typename Tp>
void createSortedSequence(Ti& sorted, std::queue<std::pair <int, int> >& unsorted, Tp& pairs)
{
    if (pairs.begin()->second == UNSET)
    {
        unsorted.push(std::make_pair(pairs.begin()->second, pairs.begin()->first));
        pairs.erase(pairs.begin());
    }
    if (pairs.empty())
        return ;
    typename Tp::iterator minIt = pairs.begin();
    for (typename Tp::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->first < minIt->first && it->second != UNSET)
            minIt = it;
    }
    unsorted.push(*minIt);
    sorted.push_back(minIt->first);
    pairs.erase(minIt);
    createSortedSequence(sorted, unsorted, pairs);
}

template <typename T>
int findBetween(int target, const T& sorted, int start, int end)
{
    if (start + 1 == end)
    {
        if (target < sorted.at(start))
            return start;
        else
            return end;
    }
    if (sorted.at(start + (end - start) / 2.0) > target)
        return (findBetween(target, sorted, start, start + ceil((end - start) / 2.0)));
    else
        return (findBetween(target, sorted, start + ceil((end - start) / 2.0), end));
}

#endif