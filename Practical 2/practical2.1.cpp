#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;
    string plate[100], target;
    cout << "Enter license plates:\n";
    for (int i = 0; i < n; i++)
        cin >> plate[i];
    cout << "Enter target license plate: ";
    cin >> target;
    int pos = 1;
    for (int i = 0; i < n; i++) {
        if (plate[i] == target) {
            pos = i;
            break;
        }
    }
    if (pos != 1)
        cout << "Vehicle found at position " << pos ;
    else
        cout << "Vehicle not found";
    return 0;
}
