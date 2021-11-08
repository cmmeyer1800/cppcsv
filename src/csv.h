#include <string>
#include <vector>
#include <fstream>

class CSV{
    private:

        std::ifstream _file;
        std::vector<std::vector<std::string>> _csv;
        void parseFile();

    public:

        CSV(std::string fileName);
        std::vector<std::string> & operator[](size_t idx);
        std::vector<std::vector<std::string>> & getCSV();
        void print();
};