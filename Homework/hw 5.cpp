#include <iostream>

int main() {

    char message[] = { 'I', ' ', 'a', 't', 'e', ' ', 't', 'a', ' ', 'c', 'o', 's', ' ', 'y', 'e', 's', 't', 'e', 'r', 'd', 'a', 'y' }; //Was asada too 


    int length = sizeof(message) / sizeof(message[0]); // size of array and message for the elements in the array


    int vowel_count = 0; //the vowels

    for (int i = 0; i < length; i++)

    {


        switch (message[i])
        {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
            vowel_count++; // Increments if  found
            break;

        default: //for breaks and non-vowel characters(needed to find online)

            break;
        }
    }

    std::cout << "The message contains " << vowel_count << " vowels." << std::endl;

    return 0;
}