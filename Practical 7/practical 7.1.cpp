#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int q[100];
    int front = -1, rear = -1;
    int choice, value;

    while (cin >> choice) {
        if (choice == 1) {
            cin >> value;

            if (rear == n - 1) {
                cout << "Queue Overflow" << endl;
            } else {
                if (front == -1)
                    front = 0;

                rear++;
                q[rear] = value;

                cout << "Front: " << q[front] << endl;
            }
        }
        else if (choice == 2) {
            if (front == -1 || front > rear) {
                cout << "Queue Underflow" << endl;
            } else {
                front++;

                if (front > rear) {
                    front = -1;
                    rear = -1;
                    cout << "Queue is Empty" << endl;
                } else {
                    cout << "Front: " << q[front] << endl;
                }
            }
        }
    }

    return 0;
}
