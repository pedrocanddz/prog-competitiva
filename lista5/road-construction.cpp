#include <bits/stdc++.h>
#define MAXN 100005
#define ll long long
#define endl '\n'

using namespace std;

vector<int> parent(MAXN), sz(MAXN);
int components, max_sz;

int find(int u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        max_sz = max(max_sz, sz[u]);
        components--;
        return true;
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    components = n, max_sz = 1;
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
    
    while (m--) {
        int u, v; cin >> u >> v;
        if (unite(u, v))
            cout << components << ' ' << max_sz << endl;
    }

    return 0;
}