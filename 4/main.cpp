#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "../helpers/helpers.h"

void lineParser(std::string line, int (&result)[4])
{
// parse the line and fill the sections array
  std::istringstream iss(line);
  char separator;
  iss >> result[0] >> separator >> result[1] >> separator >> result[2] >> separator >> result[3];
}

int findNumberOfIntersections(std::ifstream& file){
    int numberOfIntersections = 0;
    std::string line;
    int sections[4];
    while (std::getline(file, line))
    {
        lineParser(line, sections);
        if ((sections[1] >= sections[2] && sections[0] <= sections[3]) ||
            (sections[3] >= sections[0] && sections[2] <= sections[1])) {
            ++numberOfIntersections;
        }
    }
    return numberOfIntersections;
    
}

int main(int argc, char const *argv[])
{
    // read input file
    std::string filename = "input.txt";
    std::ifstream file(filename);

    int numberOfIntersections = findNumberOfIntersections(file);
    std::cout << "Number of intersections: " << numberOfIntersections << std::endl;
    return 0;
}
