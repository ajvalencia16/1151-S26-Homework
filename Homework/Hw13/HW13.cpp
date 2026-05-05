#include <iostream>
#include <map>
#include <string> //needed use of strings because the values can't be int,int 

int main() {
    // Initialize the two maps
    std::map<int, int> numbers1 = 
    {
        {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
        {6, 6}, {7, 7}, {8, 8}, {9, 9}
    };

    std::map<int, int> numbers2 = 
    {
        {1, 10}, {2, 20}, {3, 30}, {4, 40}, {5, 50},
        {6, 60}, {7, 70}, {8, 80}, {9, 90}
    };

    // Interlace the maps using iterators
    std::map<int, std::string> interlacedNumbers1;
    auto it2 = numbers2.begin();

    for (auto it1 = numbers1.begin(); it1 != numbers1.end(); ++it1) 
    {
        if (it2 != numbers2.end()) {
            interlacedNumbers1[it1->first] = std::to_string(it1->second) + ", " + std::to_string(it2->second);
            ++it2;
        } else {
            interlacedNumbers1[it1->first] = std::to_string(it1->second); // handles different sizes
        }
    }

    // Print the interlaced map (STARTER) 
    std::cout << "Interlaced map (numbers1): ";
    for (const auto& pair : interlacedNumbers1) 
    {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;

    return 0;
}