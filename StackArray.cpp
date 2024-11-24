#include <iostream>
#define MAX 100 // Define the maximum size of the stack

using namespace std;

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1; // Initialize the stack as empty
    }

    // Function to add an element to the stack
    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << "." << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into the stack." << endl;
        }
    }

    // Function to remove an element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! No elements to pop." << endl;
        } else {
            cout << arr[top--] << " popped from the stack." << endl;
        }
    }

    // Function to display the stack
    void display() {
        if (top < 0) {
            cout << "The stack is empty." << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    while (true) {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
