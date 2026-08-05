#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter your size of array"<<endl;
    cin >> n;

    int arr[1000];
    cout<<"Enter your array"<<endl;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int h;
    cout<<"Enter your hours"<<endl;
    cin >> h;

    h = h % n;

    for (int i=0; i<n; i++) {
        cout << arr[(i+h)%n] << " ";
    }

    return 0;
}
