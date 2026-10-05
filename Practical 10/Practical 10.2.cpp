#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> shelf[10];
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes:\n";

    for (int i = 0; i < n; i++) {
        cin >> code;

        int index = code % 10;
        shelf[index].push(code);
    }

    cout << "\nFinal Shelves:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (shelf[i].empty()) {
            cout << "Empty";
        } else {
            stack<int> temp = shelf[i];

            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
        }

        cout << endl;
    }

    return 0;
}
