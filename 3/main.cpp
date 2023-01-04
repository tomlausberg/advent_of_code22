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
                sum += compartment1[i] - 38;
                i++;
            }else if (compartment2[j] < compartment1[i]){
                j++;
            } else if (compartment1[i] < 'a') {
                std::cout << " " << lineCount << " " << sum << " " << compartment1[i] << " " << compartment2[j] << " " <<compartment1[i] - 38 << std::endl;

                // if the letter is uppercase
                sum += compartment1[i] - 38;
                break;
                //
            } else {
                std::cout << " " << lineCount << " " << sum << " " << compartment1[i] << " " << compartment2[j] << " " <<compartment1[i] - 96 << std::endl;
                sum += compartment1[i] - 96;
                break;
            }
        }
        lineCount++;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    // read input file
    int prioritySum = getSumOfPriorities("input.txt");
    std::cout << "Sum of priorities: " << prioritySum << std::endl;
    return 0;
}
