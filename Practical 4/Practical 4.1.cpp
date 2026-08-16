#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> q;
    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type, value, pos;

        cout << "Enter operation type (1-Front, 2-End, 3-Position): ";
        cin >> type;

        if (type == 1) {
            cout << "Enter patient token: ";
            cin >> value;
            q.push_front(value);
        }
        else if (type == 2) {
            cout << "Enter patient token: ";
            cin >> value;
            q.push_back(value);
        }
        else if (type == 3) {
            cout << "Enter patient token: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;

            if (pos <= q.size())
                q.insert(q.begin() + pos, value);
            else
                q.push_back(value);
        }

        cout << "Queue: ";
        for (int x : q)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

