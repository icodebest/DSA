#include <iostream>
#include <string>

using namespace std;

// Recursive function to reverse a string
void reverseString(string& str, int start, int end) {
    // Base case: if the start index is greater than or equal to the end index, stop recursion
    if (start >= end) {
        return;
    }

    // Swap the characters at the start and end indices
    swap(str[start], str[end]);

    // Recursively call the function with updated start and end indices
    reverseString(str, start + 1, end - 1);
}

int main() {
    // Get a string input from the user
    cout << "Enter a string: ";
    string inputString;
    getline(cin, inputString);

    // Calculate the length of the string
    int length = inputString.length();

    // Reverse the string using the recursive function
    reverseString(inputString, 0, length - 1);

    // Print the reversed string
    cout << "Reversed String: " << inputString << endl;

    return 0;
}

