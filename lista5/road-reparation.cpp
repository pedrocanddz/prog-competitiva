#include <bits/stdc++.h>
#define MAXN 100005
#define ll long long
#define endl '\n'

using namespace std;

typedef struct Edge {
    int u, v, w;
} Edge;

vector<Edge> edges;
vector<int> parent(MAXN), sz(MAXN);

int find(int u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u, sz[u] += sz[v];
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
    
    ll ans = 0, cnt = 0;

    for (auto e : edges) {
        if (unite(e.u, e.v)) {
            ans += e.w;
            if (++cnt == n-1) break;
        }
    }
    
    cout << (cnt == n - 1 ? to_string(ans) : "IMPOSSIBLE");

    return 0;
}