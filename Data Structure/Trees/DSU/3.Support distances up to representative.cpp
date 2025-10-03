#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;  // Maximum number of elements

int parent[N], sz[N];

// Initialize (make set)
void make(int v) {
    parent[v] = v;
    sz[v] = 1;
}

// Find with path compression
int find(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

// Union by size
void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    int n, m;  // n = number of nodes, m = number of operations
    cin >> n >> m;

    // Initialize all nodes
    for (int i = 1; i <= n; i++) {
        make(i);
    }

    // Example: process unions
    while (m--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    // Example: check if two nodes are connected
    int x, y;
    cin >> x >> y;
    if (find(x) == find(y))
        cout << "Connected\n";
    else
        cout << "Not Connected\n";

    return 0;
}
