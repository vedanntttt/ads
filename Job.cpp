#include <iostream>
#include <string>
using namespace std;

// Node structure for each job
struct Node {
    string jobName;
    Node* next;
};

// Queue class for job scheduling
class JobQueue {
private:
    Node* front;
    Node* rear;

public:
    JobQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // Function to insert a job into the queue
    void insertJob(const string& jobName) {
        Node* newNode = new Node();
        newNode->jobName = jobName;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Job \"" << jobName << "\" added to the queue." << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (isEmpty()) {
            cout << "Queue Underflow! No jobs to delete." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) { // If the queue becomes empty
            rear = nullptr;
        }

        cout << "Job \"" << temp->jobName << "\" removed from the queue." << endl;
        delete temp;
    }

    // Function to display the jobs in the queue
    void displayJobs() {
        if (isEmpty()) {
            cout << "The job queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Jobs in the queue (FCFS order): ";
        while (temp != nullptr) {
            cout << "\"" << temp->jobName << "\" ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    JobQueue queue;
    int choice;
    string jobName;

    while (true) {
        cout << "\nJob Scheduling Menu:\n";
        cout << "1. Insert Job\n2. Delete Job\n3. Display Jobs\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter the job name to insert: ";
                cin >> jobName;
                queue.insertJob(jobName);
                break;
            case 2:
                queue.deleteJob();
                break;
            case 3:
                queue.displayJobs();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
