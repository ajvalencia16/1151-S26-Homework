// Hw 6 pt 1.cpp : This file contains the 'main' function. Program execution begins and ends there. 


#include <iostream>

int main() 
{
    int data[] = { 1, 3, 6, 7, 9 };
    int data1[] = { 5, 3, 3, 11 };

    

    for (int i = 0; i < 4; i++) 
    {
        int temp = data[i];    // for data (1)
        data[i] = data1[i];    // put into second
        data1[i] = temp;       //transfer to 2nd array 
    }

    //for terminal so can see output for myself
    std::cout << "New data:  ";
    for (int i = 0; i < 5; i++) std::cout << data[i] << " ";

    std::cout << "\nNew data1: ";
    for (int i = 0; i < 4; i++) std::cout << data1[i] << " ";

 
}