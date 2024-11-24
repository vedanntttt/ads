#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr; // Initialize the stack as empty
    }

    // Function to add an element to the stack
    void push(int value) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Heap Overflow! Cannot push " << value << "." << endl;
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into the stack." << endl;
    }

    // Function to remove an element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! No elements to pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from the stack." << endl;
        delete temp;
    }

    // Function to display the stack
    void display() {
        if (top == nullptr) {
            cout << "The stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements are: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
