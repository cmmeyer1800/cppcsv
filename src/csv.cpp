#include "csv.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

CSV::CSV(std::string fileName) : _file(fileName){
    parseFile();
}

/*
    Params: None
    Return: None
    Action: Takes the filestream and parses it into a vector of strings,
            each of the strings being a line in the CSV file, stores it
            into a private member variable.
*/
void CSV::parseFile(){

    if(_file){
        std::string line;
        while (std::getline(_file, line)){
            std::vector<std::string> vl;
            std::stringstream ss(line);
            while(ss.good()){
                std::string substr;
                getline(ss, substr, ',');
                vl.push_back(substr);
            }
            _csv.push_back(vl);
        }
    }
    else{
        std::cout << "Fail reading failed" << std::endl;
    }
}

std::vector<std::string> & CSV::operator[](size_t idx){
    return _csv.at(idx);
}

std::vector<std::vector<std::string>> & CSV::getCSV(){
    return _csv;
}

void CSV::print(){
    for(auto r : _csv){
        for(auto c : r){
            std::cout << c << std::endl;
        }
        std::cout << std::endl;
    }
}