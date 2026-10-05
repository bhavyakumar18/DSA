#include <iostream>
using namespace std;

int main() {
    int table[10];
    int n, id;

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of student IDs: ";
    cin >> n;

    cout << "Enter student IDs:\n";

    for (int i = 0; i < n; i++) {
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);

        int index = h1;
        int count = 0;

        while (table[index] != -1 && count < 10) {
            count++;
            index = (h1 + count * h2) % 10;
        }

        if (count == 10)
            cout << "Table is full or slot cannot be found\n";
        else
            table[index] = id;
    }

    cout << "\nFinal Hash Table:\n";

    for (int i = 0; i < 10; i++)
        cout << "Slot " << i << ": " << table[i] << endl;

    return 0;
}
