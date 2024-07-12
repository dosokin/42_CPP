#include "iter.hpp"

int main(){
    int a[] = {1 , 2 , 3, 42, 666};

    iter(a, 5, printFunction);
    std::cout << std::endl;
    iter(a, 5, incrementAndPrintFunction);
}