// hw 6 pt 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main() {
    int data[] = { 1, 3, 6, 7, 9 }; //this is data i
    int data1[] = { 5, 3, 3, 11 }; //data x 

 

    for (int i = 0; i < 5; i++) //loop for data
    {

        for (int x = 0; x < 4; x++) //loop for data1
        {

            if (data[i] == data1[x]) 
            {
                std::cout << data[i] << " ";

                
            }
        }
    }

    
}
//checking which numbers the same in both arrays 