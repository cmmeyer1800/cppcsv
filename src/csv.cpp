#include "csv.h"
#include <string>
#include <fstream>

CSV::CSV(std::string fileName) : _file(fileName){
    // Constructor initializes the filestream and fills the line vector
    readLines();
}

/*
    Params: None
    Return: None
    Action: Takes the filestream and parses it into a vector of strings,
            each of the strings being a line in the CSV file, stores it
            into a private member variable.
*/
void CSV::readLines(){

    std::string line;
    while (std::getline(_file, line)){
        _lines.push_back(line);
    }
}

/*
    Params: None
    Return: Vector of strings corresponding to the lines of the CSV File
*/
std::vector<std::string> CSV::getLines(){
    return _lines;
}