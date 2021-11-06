#include <string>
#include <vector>
#include <fstream>

class CSV{
    private:

        std::ifstream _file;
        std::vector<std::string> _lines;
        void readLines();

    public:

        CSV(std::string fileName);
        std::vector<std::string> getLines();
};