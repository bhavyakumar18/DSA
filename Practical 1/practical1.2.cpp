#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter your size of array"<<endl;
    cin >> n;

    int arr[100];
    cout<<"Enter your array"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int count = 1;
        bool processed = false;

        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                processed = true;
                break;
            }
        }

        if (processed)
            continue;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > 1) {
            cout<<"borrowed more than once"<<endl;
            cout << arr[i] << " ";
        }
    }

    return 0;
}
