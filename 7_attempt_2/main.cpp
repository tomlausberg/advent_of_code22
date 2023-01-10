#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "../helpers/helpers.h"
#include "filesystem.hpp"

void parseLs(std::ifstream& file, FileSystem& fs) {
    std::string line;
    std::string arg1, arg2;
    while (file.peek() != '$' && file) {
        std::getline(file, line);
        arg1 = line.substr(0, line.find(' '));
        arg2 = line.substr(line.find(' ') + 1);

        if (arg1 == "dir") {
            fs.mkdir(arg2);
        } else {
            fs.touch(arg2, std::stoi(arg1));
        }
    }
}

void parseInput(std::ifstream& file, FileSystem& fs) {
    std::string line;
    std::string dollar;
    std::string command;
    std::string arg;
    std::vector<std::string> output;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> dollar >> command;
        if (command == "cd") {
            iss >> arg;
            fs.cd(arg);
        } else if (command == "ls") {
            parseLs(file, fs);
        }
    }
}

int main(int argc, char const* argv[]) {
    // read input file
    std::string filename = "input.txt";
    std::ifstream file(filename);

    FileSystem fs = FileSystem();

    parseInput(file, fs);

    std::cout << fs.sizeOfSmallDirs() << std::endl;

    int totalSystemSize = 70000000;
    int spaceNeeded = 30000000;
    int spaceAvailable = totalSystemSize - fs.sizeOfDirs();
    int toBeDeleted = spaceNeeded - spaceAvailable;
    int smallestDir = fs.smallestDir(toBeDeleted);

    std::cout << "total system size:\t" << totalSystemSize << std::endl;
    std::cout << "used:\t\t\t"  << fs.sizeOfDirs() << std::endl;
    std::cout << "space needed:\t\t" << spaceNeeded << std::endl;
    std::cout << "space available:\t" << spaceAvailable << std::endl;
    std::cout << "to be deleted:\t\t" << toBeDeleted << std::endl;
    
    std::cout << "smallest dir:\t\t" << smallestDir << std::endl;
    return 0;
}
