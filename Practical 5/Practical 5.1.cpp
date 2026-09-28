#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class SinglyCircular {
    Node* tail;

public:
    SinglyCircular() {
        tail = nullptr;
    }

    void join(string name) {
        Node* n = new Node(name);

        if (tail == nullptr) {
            tail = n;
            n->next = n;
        } else {
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
    }

    void leave(string name) {
        if (tail == nullptr) {
            cout << "Circle is empty\n";
            return;
        }

        Node* prev = tail;
        Node* current = tail->next;

        do {
            if (current->name == name)
                break;

            prev = current;
            current = current->next;
        } while (current != tail->next);

        if (current->name != name) {
            cout << "Student not found\n";
            return;
        }

        if (current == tail && current == tail->next) {
            tail = nullptr;
        } else {
            prev->next = current->next;

            if (current == tail)
                tail = prev;
        }

        delete current;
    }

    void display() {
        if (tail == nullptr) {
            cout << "\nCircle: Empty\n";
            return;
        }

        Node* current = tail->next;

        cout << "\nCircle: ";

        do {
            cout << current->name;

            current = current->next;

            if (current != tail->next)
                cout << " -> ";

        } while (current != tail->next);

        cout << "\n";
    }
};

int main() {
    SinglyCircular c;
    int choice;
    string name;

    do {
        cout << "\n1. Join student";
        cout << "\n2. Leave student";
        cout << "\n3. Display circle";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter student name: ";
            cin >> name;
            c.join(name);
            c.display();
        }
        else if (choice == 2) {
            cout << "Enter student name to leave: ";
            cin >> name;
            c.leave(name);
            c.display();
        }
        else if (choice == 3) {
            c.display();
        }
        else if (choice == 4) {
            cout << "Program ended\n";
        }
        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
