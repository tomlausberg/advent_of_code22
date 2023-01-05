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
    while (true) {
        int p = file.peek();
        if (p == '$' || p == EOF) {
            break;
        }
        std::getline(file, line);
        arg1 = line.substr(0, line.find(' '));
        arg2 = line.substr(line.find(' ') + 1);

        if (arg1 == "dir") {
            fs.mkdir(arg2);
        } else {
            fs.mkfil(arg2, std::stoi(arg1));
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
    std::string filename = "testinput.txt";
    std::ifstream file(filename);

    FileSystem fs = FileSystem();

    parseInput(file, fs);
    fs.ls();
    fs.cd("/");
    fs.ls();

    return 0;
}
