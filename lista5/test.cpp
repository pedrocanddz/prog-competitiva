#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int parent[maxn], sz[maxn], components, max_sz;

int find(int u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        max_sz = max(max_sz, sz[u]);
        components--;
    }
}

int main() {
    int n, m; cin >> n >> m;
    components = n, max_sz = 1;
    iota(parent, parent+n+1, 0);
    fill(sz, sz+n+1, 1);
    
    while (m--) {
        int u, v; cin >> u >> v;
        unite(u, v);
        cout << components << ' ' << max_sz << '\n';
    }
}