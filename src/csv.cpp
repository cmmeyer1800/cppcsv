#include "csv.h"
#include <string>
#include <iostream>


/*
    Constructor initializes file stream to CSV and
    then calls parseFile() to break it into dataset
*/
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
            _csv.push_back(rowParse(line));
        }
    }
    else{
        std::cout << "File reading failed" << std::endl;
    }
}


/*
    Params: None
    Return: Specific row of CSV by using array access operator.
    Action: None
*/
std::vector<std::string> & CSV::operator[](size_t idx){
    return _csv.at(idx);
}


/*
    Params: None
    Return: Vector of strings
    Action: Parses lines into vector of string seperated by commas
*/
std::vector<std::string> CSV::rowParse(std::string rowString){
    std::vector<std::string> rowVector;
    std::vector<int> indices;

    //  While loop pushes comma indices to indices vector if they
    //      are not inside a set of quotes.
    size_t idx = 0;
    bool inQuotes = false;
    while(idx < rowString.size()){
        if(rowString[idx] == '"'){
            inQuotes = !inQuotes;
        }
        else if(rowString[idx] == ','){
            if(!inQuotes){
                indices.push_back(idx);
            }
        }
        idx++;
    }
    // Now we take these indices and use them to get the substrings we want.
    for(size_t i = 0; i < indices.size(); i++){
        if(i == 0){
            rowVector.push_back(rowString.substr(0, indices[0]));
        }
        else{
            rowVector.push_back(rowString.substr(indices[i-1]+1, indices[i]-indices[i-1]-1));
        }
    }
    rowVector.push_back(rowString.substr(indices[indices.size()-1]+1));

    return rowVector;
}


/*
    Params: None
    Return: CSV as vector of vectors of strings.
    Action: None
*/
std::vector<std::vector<std::string>> & CSV::getCSV(){
    return _csv;
}


/*
    Params: None
    Return: None
    Action: Prints the CSV file to console with space
            seperating row elements and newlines seperating
            rows.
*/
void CSV::print(){
    for(auto r : _csv){
        for(auto c : r){
            std::cout << c << "|";
        }
        std::cout << std::endl;
    }
}