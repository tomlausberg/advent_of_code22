#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//sort
#include <algorithm>

// read calories from txt file and store in vector
std::vector<int> readCalories(std::string filename)
{
    std::vector<int> calories;
    std::ifstream file(filename);
    int currentCalories = 0;
    int calorie;

    std::string line;
    int lineCount = 0;
    while (std::getline(file, line))
    {
        std::cout << "l " << lineCount << line;
        if (line.empty())
        {
            calories.push_back(currentCalories);
            std::cout << " empty line pushing " << currentCalories << std::endl;
            currentCalories = 0;
        }
        else
        {
            calorie = std::stoi(line);
            currentCalories += calorie;
            std::cout << " calorie " << calorie << " total " << currentCalories << std::endl;
        }
    }

    return calories;
}

int getMaxCalories(std::string filename)
{
    std::ifstream calorieFile(filename);
    int maxCalories = 0;
    int maxCaloriesIndex = 0;
    int currentCalories = 0;
    int currentIndex = 1;
    std::string line;
    int currentline = 0;

    while (std::getline(calorieFile, line))
    {
        currentline++;
        if (line.empty())
        {
            if (currentCalories > maxCalories)
            {

                maxCalories = currentCalories;
                maxCaloriesIndex = currentIndex;
            }
            currentCalories = 0;
            currentIndex++;
        }
        else
        {
            currentCalories += std::stoi(line);
        }
    }
    if (currentCalories > maxCalories)
    {
        maxCalories = currentCalories;
        maxCaloriesIndex = currentIndex;
    }
    currentCalories = 0;
    currentIndex++;
    std::cout << "total entries " << currentIndex << std::endl;
    return maxCalories;
}

std::vector<int> getCalories(std::string filename)
{
    std::vector<int> calories;
    std::ifstream file(filename);
    int currentCalories = 0;
    int calorie;

    std::string line;
    int lineCount = 0;
    while (std::getline(file, line))
    {
        if (line.empty())
        {
            calories.push_back(currentCalories);
            currentCalories = 0;
        }
        else
        {
            calorie = std::stoi(line);
            currentCalories += calorie;
        }
    }
    calories.push_back(currentCalories);

    return calories;
}
int main(int argc, char const *argv[])
{
    // std::vector<int> calories;
    // calories = readCalories("   input.txt");
    // std::cout << "Number of entries: " << calories.size() << std::endl;
    // //get max entry
    // int max = 0;
    // uint maxIndex = 0;
    // for (int i = 0; i < calories.size(); i++) {
    //     if (calories[i] > max) {
    //         max = calories[i];
    //         maxIndex = i;
    //     }
    // }
    // std::cout << "Max calories: " << max << std::endl;
    // std::cout << "Max calories index: " << maxIndex+1 << std::endl;

    int maxCaloriesIndex = getMaxCalories("input2.txt");
    std::cout << "Max calories: " << maxCaloriesIndex << std::endl;

    std::vector<int> calories = getCalories("input2.txt");
    std::cout << "Number of entries: " << calories.size() << std::endl;
    // sort list and get top three entries
    std::sort(calories.begin(), calories.end(), std::greater<int>());
    std::cout << "Top three entries: " << std::endl;
    int totalCalories = 0;
    for (int i = 0; i < 3; i++) {
        totalCalories += calories[i];
        std::cout << calories[i] << std::endl;
    }
    std::cout << "Total calories: " << totalCalories << std::endl;
    return 0;
}
