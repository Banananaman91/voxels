#include "FileReader.h"
using namespace freader;

std::string FileReader::ReadFile(const char* filePath){
    std::stringstream content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    content << fileStream.rdbuf();
    std::string returnString = content.str();

    fileStream.close();
    return returnString;
}