#include <iostream>
using namespace std;

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    cout << "BFS Traversal: ";

    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}

void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int start;
    cin >> start;

    BFS(start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS Traversal: ";
    DFS(start);
    cout << endl;

    return 0;
}
