#include<fstream>
#include<iostream>
#include<vector>
#include<string>

#include "helpers/helpers.h"

//read txt file and store as string
std::string readFileToString(std::string filename)
{
    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    return content;
}
