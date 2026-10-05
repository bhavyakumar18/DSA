#include <iostream>
#include <queue>
using namespace std;

int graph[10][10];
int visited[10];
int n;

void DFS(int start) {
    cout << start << " ";
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int visited[10] = {0};
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, u, v, start;

    cout << "Enter number of buildings: ";
    cin >> n;

    cout << "Enter number of roads: ";
    cin >> edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter roads:\n";

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting building: ";
    cin >> start;

    cout << "DFS: ";
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(start);

    cout << "\nBFS: ";
    BFS(start);

    return 0;
}
