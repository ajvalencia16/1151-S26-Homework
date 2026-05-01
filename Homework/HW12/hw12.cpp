#include <iostream>
#include <vector>

int main() 
{
    // 1. Initialize the two vectors
    std::vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> numbers2 = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int* ptr = numbers2.data();     // Pointer to traverse numbers2


    auto it = numbers1.begin();

    for (int i = 0; i < (int)numbers2.size(); i++) 
    {
        if (it != numbers1.end()) ++it;      
        it = numbers1.insert(it, *ptr);      
        ++it;                                
        ++ptr;                               
    }

    // 3. Print the interlaced vector
    std::cout << "Interlaced vector (numbers1): ";
    for (int num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}