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



int main(int argc, char const *argv[]) {
    // read input file
    std::string filename = "input.txt";
    std::ifstream file(filename);


    FileSystem fs = FileSystem();
    fs.cd("/");
    return 0;
}
