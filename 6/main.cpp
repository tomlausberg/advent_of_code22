#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <queue>
#include "../helpers/helpers.h"


uint getFirstPacketMarker(std::istringstream& iss)
{
    uint position = 0;
    int counter = 0;
    char queue[3];
    char c;

    //populate the queue
    iss >> queue[0] >> queue[1] >> queue[2];
    std::cout << "q:" << queue[0] << queue[1] << queue[2] << std::endl; 
    if (queue[0] == queue[1]) {
        counter = 1;
    } else if (queue[1] == queue[2]) {
        counter = 2;
    } else if (queue[0] == queue[2]) {
        counter = 1;
    } else {
        counter = 0;
    }

    while (iss >> c)
    {
        std::cout << position <<":" << queue[0] << queue[1] << queue[2] << " c:" << c << " " << counter<< std::endl;
        if (c==queue[position%3]){
            counter = std::max(counter, 1);
        }
        if (c==queue[(position+1)%3]){
            counter = std::max(counter, 2);
        }
        if (c==queue[(position+2)%3]){
            counter = std::max(counter, 3);
        }

        if (counter == 0) {
            return position + 4;
        } else {
            queue[position%3] = c;
            --counter;
            ++position;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    // read input file
    std::string filename = "input.txt";
    std::ifstream file(filename);

    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);
    
    // std::istringstream iss("bvwbjplbgvbhsrlpgdmjqwftvncz");

    uint firstPacketMarker = getFirstPacketMarker(iss);
    std::cout << "First packet marker: " << firstPacketMarker << std::endl;
    return 0;
}
