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


void parseInput(std::ifstream file, FileSystem& fs) {
    std::string line;
    while (std::getline(file, line)) {
        
    }
}


int main(int argc, char const *argv[]) {
    // read input file
    std::string filename = "input.txt";
    std::ifstream file(filename);

    FileSystem fs = FileSystem();
    // fs.cd("/");
    return 0;
}
