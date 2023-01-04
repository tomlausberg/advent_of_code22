#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stack>
#include "../helpers/helpers.h"


void parseInput(std::ifstream &file, std::vector<std::vector<char>> &stacks, std::vector<std::array<int, 3>> &moves)
{
    //init stacks and moves
    stacks.resize(9);
    moves.resize(0);

    // parse stacks on the first 9 lines
    std::string line;
    for(int i = 1; i < 9; i++){
        std::getline(file, line);
        for(int j = 0; j < 9; j++){
            if(line[j*4] == '['){
                    stacks[j].push_back(line[j*4+1]);
            }
        }
    }
    // skip empty lines
    std::getline(file, line);
    std::getline(file, line);

    // parse moves until the end of the file
    //format: "move x from b to c"
    std::array<int, 3> move;
    while(std::getline(file, line)){
        std::istringstream iss(line);
        std::string word;
        iss >> word >> move[0] >> word >> move[1] >> word >> move[2];
        moves.push_back(move);
    }
    //flip order of stacks
    for(auto& stack : stacks){
        std::reverse(stack.begin(), stack.end());
    }
}

void doMove(std::vector<std::vector<char>> &stacks, int numberOfPackages, int from, int to)
{
    //move last numberOfPackages from stack from to stack to
    for(int i = 0; i < numberOfPackages; i++){
        stacks[to-1].push_back(stacks[from-1].back());
        stacks[from-1].pop_back();
    }
}

void doOrderedMove(std::vector<std::vector<char>> &stacks, int numberOfPackages, int from, int to)
{
    //move last numberOfPackages from stack from to stack to
    stacks[to-1].insert(stacks[to-1].end(), stacks[from-1].end() - numberOfPackages, stacks[from-1].end());
    stacks[from-1].erase(stacks[from-1].end() - numberOfPackages, stacks[from-1].end());   
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

uint sumPriortiesOfTopPackages(std::vector<std::vector<char>> stacks)
{
    uint sum = 0;
    for(auto stack : stacks){
        if(stack.size() > 0){
            sum += getPriority(stack.back());
        }
    }
    return sum;
}

void printTopPackages(std::vector<std::vector<char>> stacks)
{
    for(auto stack : stacks){
        if(stack.size() > 0){
            std::cout << stack.back();
        }
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    // read input file
    std::string filename = "input.txt";
    std::ifstream file(filename);

    std::vector<std::vector<char>> stacks(9);
    std::vector<std::array<int, 3>> moves;
    parseInput(file, stacks, moves);

    // print stacks
    for(auto stack : stacks){
        for(auto package : stack){
            std::cout << package << " ";
        }
        std::cout << std::endl;
    }
    
    // do moves
    int moveCount = 0;
    for(auto move : moves){
        moveCount++;
        doOrderedMove(stacks, move[0], move[1], move[2]);
    }


    // print sum
    std::cout << "Sum of priorities of top packages: " << sumPriortiesOfTopPackages(stacks) << std::endl;
    printTopPackages(stacks);

    return 0;
}
