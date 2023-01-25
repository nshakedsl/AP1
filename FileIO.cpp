#include "FileIO.h"

std::string FileIO::read() {
    std::ifstream myFile(fileName);
    // file not found
    if (!myFile.is_open()) {
        throw std::invalid_argument("can't open file");
    }
    // Read the entire file into a string
    std::string content((std::istreambuf_iterator<char>(myFile)), std::istreambuf_iterator<char>());
    return content;
}

void FileIO::write(const std::string &x) {

    std::ofstream myFile(fileName);
    // file not found
    if (!myFile.is_open()) {
        throw std::invalid_argument("can't open file");
    }
    // Write the string x to the file
    myFile << x;
    myFile.close();
}

void FileIO::setPath(std::string path) {
    // set the fileName variable to the given path
    fileName = path;

}
