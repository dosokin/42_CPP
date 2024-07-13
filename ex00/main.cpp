#include <vector>
#include <iostream>
#include "easyfind.tpp"

int main (){

    try {
        std::vector<int> vect1;
        vect1.push_back(1);
        vect1.push_back(2);
        vect1.push_back(3);
        std::cout << *easyfind(vect1, 3) << std::endl;
    }
    catch (std::exception const &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::vector<int> vect1;
        vect1.push_back(111);
        vect1.push_back(222);
        vect1.push_back(333);
        std::cout << *easyfind(vect1, 222) << std::endl;
    }
    catch (std::exception const &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::vector<int> vect1;
        vect1.push_back(111);
        vect1.push_back(222);
        vect1.push_back(333);
        std::cout << *easyfind(vect1, 999) << std::endl;
    }
    catch (std::exception const &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

}