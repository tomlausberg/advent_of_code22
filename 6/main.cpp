#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cctype>
#include "../helpers/helpers.h"

uint getFirstPacketMarker(std::istringstream &iss) {
    uint position = 0;
    int counter = 0;
    char queue[3];
    char c;

    // populate the queue
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

    while (iss >> c) {
        std::cout << position << ":" << queue[0] << queue[1] << queue[2]
                  << " c:" << c << " " << counter << std::endl;
        if (c == queue[position % 3]) {
            counter = std::max(counter, 1);
        }
        if (c == queue[(position + 1) % 3]) {
            counter = std::max(counter, 2);
        }
        if (c == queue[(position + 2) % 3]) {
            counter = std::max(counter, 3);
        }

        if (counter == 0) {
            return position + 4;
        } else {
            queue[position % 3] = c;
            --counter;
            ++position;
        }
    }
    return 0;
}

uint getFirstMessageMarker(std::istringstream &iss, int markerSize) {
    int position = 0;
    int counter = markerSize;
    char *queue = new char[markerSize];
    char c;

    // populate the queue
    for (uint i = 0; i < markerSize; ++i) {
        queue[i] = '0';
    }
    int currentPos;
    while (!iss.eof()) {
        //add new char to queue
        currentPos = position % markerSize;
        iss >> queue[currentPos];
        //check if it is a hit
        for(int i = 0; i < markerSize; ++i){
            if(queue[i] == queue[currentPos] && i != currentPos){
                int disctance = (i-currentPos) % markerSize;
                disctance = disctance < 0 ? disctance + markerSize : disctance;                
                // printf("\033[31m(%i,%i,%i,%i)\033[0m ",currentPos,i,disctance,counter);
                counter = std::max(counter,disctance);
            }
        }
        if (counter == 0) {
            return position + 1;
        }
        counter--;
        position++;
    }

    printf("No message marker found. counter: %i\n", counter);
    delete queue;
    return 0;
}


int main(int argc, char const *argv[]) {
    // read input file
    std::string filename = "input.txt";
    std::ifstream file(filename);

    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);

    // std::istringstream iss("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg");

    // uint firstPacketMarker = getFirstPacketMarker(iss);
    uint firstPacketMarker = getFirstMessageMarker(iss,14);
    std::cout << "First packet marker: " << firstPacketMarker << std::endl;

    return 0;
}
