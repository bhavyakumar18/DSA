#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key) {
    int low=0,high=n;

    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]==key)
            return mid;
        else if (arr[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }

    return -1;
}
int main() {
    int n;
    int arr[100];
    cout<<"Enter your size of array"<<endl;
    cin >> n;

    cout<<"Enter your array"<<endl;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    cout<<"Enter your key"<<endl;
    int key;
    cin >> key;

    int pos1 =BinarySearch(arr, n, key);
    cout << "key is at index : " << pos1 << endl;
    cout << "key is at position : " << pos1+1 << endl;
    return 0;
}
