
#include "PmergeMe.hpp"


int safe_atoi(std::string s)
{
    unsigned int uiresult;
    std::stringstream ss;
    ss << s;
    ss >> uiresult;

    if (uiresult > MAX_INT)
        throw std::logic_error("int overflow");
    int result = static_cast<int>(uiresult);
    return result;
}

void groupElements(std::vector<std::vector<std::pair<int, int> > > &unsortedGrouped, std::queue<std::pair<int, int> > &elements, size_t capacity, size_t groupNumber)
{
    if (elements.empty())
        return ;
    std::vector<std::pair<int,int> > group;
    for (size_t i = 0; i < capacity && !elements.empty(); i++)
    {
        group.push_back(elements.front());
        elements.pop();
    }
    unsortedGrouped.push_back(group);
    size_t nextCapacity = std::pow(2, groupNumber + 2) - capacity;
    groupElements(unsortedGrouped, elements, nextCapacity, groupNumber + 1);
}

void groupElements(std::deque<std::deque<std::pair<int, int> > > &unsortedGrouped, std::queue<std::pair<int, int> > &elements, size_t capacity, size_t groupNumber)
{
    if (elements.empty())
        return ;
    std::deque<std::pair<int,int> > group;
    for (size_t i = 0; i < capacity && !elements.empty(); i++)
    {
        group.push_back(elements.front());
        elements.pop();
    }
    unsortedGrouped.push_back(group);
    size_t nextCapacity = std::pow(2, groupNumber + 2) - capacity;
    groupElements(unsortedGrouped, elements, nextCapacity, groupNumber + 1);
}

std::vector<int> vectorSort(int argc, char **argv) {

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> base;
    base = extractInts(base, argc, argv);

    printElement(base, BEFORE);

    bool impair = base.size() % 2 != 0;

    // Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
    for (std::vector<int>::iterator it = base.begin(); it != base.end() && it + 1 != base.end(); it = it + 2) {
        std::pair<int, int> pair = std::make_pair(*(it), *(it + 1));
        pairs.push_back(pair);
    }
    if (impair) {
        std::pair<int, int> single = std::make_pair(*(base.end() - 1), UNSET);
        pairs.push_back(single);
    }

    // Perform [n / 2] comparisons, one per pair, to determine the larger of the two elements in each pair.
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it->second != UNSET) {
            if (it->first < it->second) {
                int tempo = it->first;
                it->first = it->second;
                it->second = tempo;
            }
        }
    }

    //Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of [n/2] of the input elements, in ascending order.
    std::vector<int> sorted;
    std::queue<std::pair<int, int> > unsorted;
    createSortedSequence(sorted, unsorted, pairs);

    //Insert at the start of S the element that was paired with the first and smallest element of S.
    sorted.insert(sorted.begin(), unsorted.front().second);
    unsorted.pop();


    //Partition the uninserted elements y into groups with contiguous indexes. \
    // There are two elements in the first group, and the sums of sizes of every two adjacent groups form a sequence of powers of two.\
    // Thus, the sizes of groups are: 2, 2, 6, 10, 22, 42, ...
    std::vector<std::vector<std::pair<int, int> > > groups;
    groupElements(groups, unsorted, 2, 0);


    //Order the uninserted elements by their groups (smaller indexes to larger indexes), \
    // but within each group order them from larger indexes to smaller indexes
    std::queue<std::pair<int, int> > unsortedGrouped;
    for (size_t i = 0; i < groups.size(); i++)
    {
        std::vector<std::pair<int, int> > current = groups.at(i);
        for (std::vector<std::pair<int, int> >::iterator it = current.end() - 1;;it--)
        {
            unsortedGrouped.push(*it);
            if (it == current.begin())
                break;
        }
    }

    //Use this ordering to insert the elements y into S. For each element y use a binary search from the start of S
    for (std::pair<int,int> current;!unsortedGrouped.empty(); unsortedGrouped.pop())
    {
        current = unsortedGrouped.front();
        std::vector<int>::iterator it = std::find(sorted.begin() + 2, sorted.end(), current.first);
        int appairedIndex = it - sorted.begin();
        int position = findBetween(current.second, sorted, 0, appairedIndex);
        sorted.insert(sorted.begin() + position, current.second);
    }

    return sorted;
}

std::deque<int> dequeSort(int argc, char **argv) {

    std::deque<std::pair<int, int> > pairs;
    std::deque<int> base;
    base = extractInts(base, argc, argv);

    bool impair = base.size() % 2 != 0;

    // Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
    for (std::deque<int>::iterator it = base.begin(); it != base.end() && it + 1 != base.end(); it = it + 2) {
        std::pair<int, int> pair = std::make_pair(*(it), *(it + 1));
        pairs.push_back(pair);
    }
    if (impair) {
        std::pair<int, int> single = std::make_pair(*(base.end() - 1), UNSET);
        pairs.push_back(single);
    }

    // Perform [n / 2] comparisons, one per pair, to determine the larger of the two elements in each pair.
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        if (it->second != UNSET) {
            if (it->first < it->second) {
                int tempo = it->first;
                it->first = it->second;
                it->second = tempo;
            }
        }
    }

    //Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of [n/2] of the input elements, in ascending order.
    std::deque<int> sorted;
    std::queue<std::pair<int, int> > unsorted;
    createSortedSequence(sorted, unsorted, pairs);

    //Insert at the start of S the element that was paired with the first and smallest element of S.
    sorted.insert(sorted.begin(), unsorted.front().second);
    unsorted.pop();


    //Partition the uninserted elements y into groups with contiguous indexes. \
    // There are two elements in the first group, and the sums of sizes of every two adjacent groups form a sequence of powers of two.\
    // Thus, the sizes of groups are: 2, 2, 6, 10, 22, 42, ...
    std::deque<std::deque<std::pair<int, int> > > groups;
    groupElements(groups, unsorted, 2, 0);


    //Order the uninserted elements by their groups (smaller indexes to larger indexes), \
    // but within each group order them from larger indexes to smaller indexes
    std::queue<std::pair<int, int> > unsortedGrouped;
    for (size_t i = 0; i < groups.size(); i++)
    {
        std::deque<std::pair<int, int> > current = groups.at(i);
        for (std::deque<std::pair<int, int> >::iterator it = current.end() - 1;;it--)
        {
            unsortedGrouped.push(*it);
            if (it == current.begin())
                break;
        }
    }

    //Use this ordering to insert the elements y into S. For each element y use a binary search from the start of S
    for (std::pair<int,int> current;!unsortedGrouped.empty(); unsortedGrouped.pop())
    {
        current = unsortedGrouped.front();
        std::deque<int>::iterator it = std::find(sorted.begin() + 2, sorted.end(), current.first);
        int appairedIndex = it - sorted.begin();
        int position = findBetween(current.second, sorted, 0, appairedIndex);
        sorted.insert(sorted.begin() + position, current.second);
    }

    return sorted;
}