#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "../helpers/helpers.h"

std::string sortString(std::string str)
{
    sort(str.begin(), str.end());
    return str;
} 




int getPriority(char letter)
{
    int priority = 0;
    if(letter >= 'a' && letter <= 'z'){
        // if the letter is lowercase
        priority = letter - 96;
    } else if (letter >= 'A' && letter <= 'Z') {
        // if the letter is uppercase
        priority = letter - 38;
    }
    // std::cout << "Letter: " << letter << " Priority: " << priority << std::endl; 
    return priority;
}

int getSumOfPriorities(std::string filename)
{
    std::ifstream file(filename);
    std::string line;
    int lineCount = 0;
    int sum = 0;
    int compartmentSize = 0;
    while(std::getline(file, line)){
        compartmentSize = line.size()/2;
        std::string compartment1 = sortString(line.substr(0, compartmentSize));
        std::string compartment2 = sortString(line.substr(compartmentSize, compartmentSize*2));
        int i = 0;
        int j = 0;
        while( i < compartmentSize && j < compartmentSize){
            if(compartment1[i] < compartment2[j]){
                i++;
            }else if (compartment2[j] < compartment1[i]){
                j++;
            } else if (compartment1[i] == compartment2[j]) {
                sum += getPriority(compartment1[i]);
                break;
            }
        }
        lineCount++;
    }
    return sum;
}


int sumOfBadges(std::string filename)
{
    std::ifstream file(filename);
    int sum = 0;
    std::string elf1;
    std::string elf2;
    std::string elf3;

    while(true){
        getline(file, elf1);
        getline(file, elf2);
        getline(file, elf3);
        
        for(char badge : elf1){
            if(elf2.find(badge) != std::string::npos && elf3.find(badge) != std::string::npos){
                sum += getPriority(badge);
                break;
            }
        }
        if(file.eof()){
            break;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    // read input file
    int prioritySum = getSumOfPriorities("input.txt");
    std::cout << "Sum of priorities: " << prioritySum << std::endl;
    int badgeSum = sumOfBadges("input.txt");
    std::cout << "Sum of badges: " << badgeSum << std::endl;
    return 0;
}
