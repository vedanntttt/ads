#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to reverse a string using a stack
string reverseString(const string& str) {
    stack<char> s;
    string reversed = "";

    // Push each character onto the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Pop each character from the stack to build the reversed string
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    string reversed = reverseString(str);
    return str == reversed;
}

int main() {
    string input;
    char choice;

    do {
        cout << "Enter a string: ";
        cin >> input;

        // Part (a): Print the original and reversed string
        string reversedString = reverseString(input);
        cout << "Original string: " << input << endl;
        cout << "Reversed string: " << reversedString << endl;

        // Part (b): Check if the string is a palindrome
        if (isPalindrome(input)) {
            cout << "The given string is a palindrome." << endl;
        } else {
            cout << "The given string is not a palindrome." << endl;
        }

        // Ask the user if they want to continue
        cout << "\nDo you want to check another string? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting program." << endl;
    return 0;
}
