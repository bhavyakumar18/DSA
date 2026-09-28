#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;
    int choice;
    string patient;

    while (cin >> choice) {
        if (choice == 1) {
            cin >> patient;
            q.push(patient);

            cout << "Front: " << q.front() << endl;
        }
        else if (choice == 2) {
            if (q.empty()) {
                cout << "Queue is Empty" << endl;
            } else {
                q.pop();

                if (q.empty())
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Front: " << q.front() << endl;
            }
        }
    }

    return 0;
}
