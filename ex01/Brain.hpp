#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
public:
    Brain();
    Brain(const Brain& Other);
    Brain&  operator=(const Brain& Other);
    ~Brain();
    std::string     *get_ideas;
private:
    std::string     _ideas[100];
};

#endif
