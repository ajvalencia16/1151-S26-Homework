#include <iostream>
#include <stdexcept> // Gives us standard error types
#include <string>

using namespace std;

// 1. A very simple custom exception
class CustomException : public exception {
public:
    const char* what() const noexcept override {
        return "Error in nestedFunction";
    }
};



double divide(int num, int den) {
    if (den == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }
    return (double)num / den; 
}

int accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }
    return arr[index];
}

void nestedFunction() {
    throw CustomException(); 
}

void outerFunction() {
    try {
        nestedFunction();
    } catch (const CustomException& e) 
    {
        cout << "Caught exception in outerFunction: " << e.what() << endl;
        throw; 
    }
}



int main() 
{
    // Part A: Nested Exception Demo
    try 
    {
        outerFunction();
    } catch (const CustomException& e) 
    {
        cout << "Caught rethrown exception in main: " << e.what() << endl;
    }

    cout << endl;

    // Part B: Division Demo
    int n, d;
    cout << "Enter numerator: "; cin >> n;
    cout << "Enter denominator: "; cin >> d;

    try 
    {
        cout << "Result: " << divide(n, d) << endl;
    } catch (const runtime_error& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl;

    // Part C: Array Demo
    int myNumbers[5] = {10, 20, 30, 40, 50}; 
    int idx;
    cout << "Enter index to access (0-4): "; cin >> idx; // idx is the index to access, which out of bounds will throw an exception

    try 
    {
        cout << "Value: " << accessArray(myNumbers, 5, idx) << endl;
    } catch (const out_of_range& e) //e is the error object for out of bounds access
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}