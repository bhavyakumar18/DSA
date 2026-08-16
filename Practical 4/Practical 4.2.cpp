#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> q;
    int n, value;

    cout << "Enter number of patients: ";
    cin >> n;

    cout << "Enter patient tokens: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push_back(value);
    }

    cout << "Queue from front to back: ";
    for (int x : q)
        cout << x << " ";

    cout << "\nEnter token to delete: ";
    cin >> value;

    for (auto it = q.begin(); it != q.end(); it++) {
        if (*it == value) {
            q.erase(it);
            break;
        }
    }

    cout << "Queue after deletion: ";
    for (int x : q)
        cout << x << " ";

    cout << "\nQueue from last to first: ";
    for (auto it = q.rbegin(); it != q.rend(); it++)
        cout << *it << " ";

    return 0;
}
