#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist {
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
    }

    void addBeginning(string song) {
        Node* n = new Node(song);

        if (head == nullptr) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void addEnd(string song) {
        Node* n = new Node(song);

        if (tail == nullptr) {
            head = tail = n;
        } else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
    }

    void insertAfter(string target, string song) {
        Node* current = head;

        while (current != nullptr && current->song != target)
            current = current->next;

        if (current == nullptr) {
            cout << "Song not found\n";
            return;
        }

        Node* n = new Node(song);

        n->prev = current;
        n->next = current->next;

        if (current->next != nullptr)
            current->next->prev = n;
        else
            tail = n;

        current->next = n;
    }

    void removeFirst() {
        if (head == nullptr) {
            cout << "Playlist is empty\n";
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    int count() {
        int c = 0;
        Node* current = head;

        while (current != nullptr) {
            c++;
            current = current->next;
        }

        return c;
    }

    void display() {
        Node* current = head;

        cout << "\nPlaylist: ";

        if (current == nullptr) {
            cout << "Empty";
        }

        while (current != nullptr) {
            cout << current->song;

            if (current->next != nullptr)
                cout << " -> ";

            current = current->next;
        }

        cout << "\nNumber of songs: " << count() << "\n";
    }
};

int main() {
    Playlist p;
    int choice;
    string song, target;

    do {
        cout << "\n1. Add at beginning";
        cout << "\n2. Add at end";
        cout << "\n3. Insert after song";
        cout << "\n4. Remove first song";
        cout << "\n5. Display playlist";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter song name: ";
            cin >> song;
            p.addBeginning(song);
            p.display();
        }
        else if (choice == 2) {
            cout << "Enter song name: ";
            cin >> song;
            p.addEnd(song);
            p.display();
        }
        else if (choice == 3) {
            cout << "Enter song after which to insert: ";
            cin >> target;
            cout << "Enter new song name: ";
            cin >> song;
            p.insertAfter(target, song);
            p.display();
        }
        else if (choice == 4) {
            p.removeFirst();
            p.display();
        }
        else if (choice == 5) {
            p.display();
        }
        else if (choice == 6) {
            cout << "Program ended\n";
        }
        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
