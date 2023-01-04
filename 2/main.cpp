#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "../helpers/helpers.h"

int winner(char p1, char p2)
{
    // 1 = p1 wins, 2 = p2 wins, 0 = tie
    switch (p1)
    {
    case 'A':
        switch (p2)
        {
        case 'X':
            return 0;
        case 'Y':
            return 2;
        case 'Z':
            return 1;
        default:
            break;
        }
        break;
    case 'B':
        switch (p2)
        {
        case 'X':
            return 1;
        case 'Y':
            return 0;
        case 'Z':
            return 2;
        default:
            break;
        }
        break;
    case 'C':
        switch (p2)
        {
        case 'X':
            return 2;
        case 'Y':
            return 1;
        case 'Z':
            return 0;
        default:
            break;
        }
        break;
    default:
        break;
    }
    //throw error
    return -1;
}

int p2_points(char p1, char p2){
    int choicePoints;
    switch (p2){

    case 'X':
        choicePoints = 1;
        break;
    case 'Y':
        choicePoints = 2;
        break;
    case 'Z':
        choicePoints = 3;
        break;
    default:
        break;
    }
    int w = winner(p1, p2);
    if (w == 2){
        return choicePoints + 6;
    }
    else if (w == 0){
        return choicePoints + 3;
    }
    else{
        return choicePoints;
    }

    //throw error
    return -1;
}

int correctMove(char p1, char p2){
    switch (p1)
    {
    case 'A':
        switch (p2)
        {
        case 'X':
            return 2;
        case 'Y':
            return 0;
        case 'Z':
            return 1;
        default:
            break;
        }
        break;
    case 'B':
        switch (p2)
        {
        case 'X':
            return 0;
        case 'Y':
            return 1;
        case 'Z':
            return 2;
        default:
            break;
        }
        break;
    case 'C':
        switch (p2)
        {
        case 'X':
            return 1;
        case 'Y':
            return 2;
        case 'Z':
            return 0;
        default:
            break;
        }
        break;
    default:
        return -1;
    }
}  

int p2_points2(char p1, char p2){
    int choicePoints;
    switch (p2){

    case 'X':
        choicePoints = 0;
        break;
    case 'Y':
        choicePoints = 3;
        break;
    case 'Z':
        choicePoints = 6;
        break;
    default:
        break;
    }
    
    return choicePoints + correctMove(p1, p2) + 1;
}
// get total points
int getTotalPoints(std::string filename)
{
    std::ifstream file(filename);
    std::string line;

    int totalPoints = 0;
    char p1;
    char p2;

    while (std::getline(file, line))
    {
        p1 = line[0];
        p2 = line[2];
        totalPoints += p2_points2(p1, p2);
    }
    return totalPoints;
}


int main(int argc, char const *argv[])
{
    // read input file
    int totalPoints = getTotalPoints("input.txt");
    std::cout << "Total points: " << totalPoints << std::endl;
    return 0;
}
