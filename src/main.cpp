#include <iostream>
#include "csv.h"

int main(){
    CSV test("/Users/collin/code/cppcsv/test.txt");
    for(auto l : test.getLines()){
        std::cout << l;
    }
}