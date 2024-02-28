#include <iostream>
#include <stack>
using namespace std;
// Function to reverse a string using a stack
string reverseString(const string& input) {
    stack<char> charStack;  // Create an empty stack of characters

    // Push each character from the input string onto the stack
   for (size_t i = 0; i < input.size(); ++i) {
    char c = input[i];
    charStack.push(c);
}


    string reversedString;  // Create an empty string to store the reversed result

    // Pop characters from the stack and append them to the reversedString
    while (!charStack.empty()) {
        reversedString += charStack.top();  // Append the character at the top of the stack
        charStack.pop();  // Pop the character from the stack
    }

    return reversedString;  // Return the reversed string
}

int main() {
    string input = "Data Structures";  // Define the input string
    string reversed = reverseString(input);  // Call the function to reverse the input string

    cout << "Original String: " << input << endl;  // Print the original string
    cout << "Reversed String: " << reversed << endl;  // Print the reversed string

    return 0;
}

