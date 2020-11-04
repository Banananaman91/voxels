#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace freader {
    class FileReader{
        public:
            std::string ReadFile(std::string filePath);
    };
}