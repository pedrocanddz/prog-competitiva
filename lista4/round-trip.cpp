#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

vector<int> adj[MAXN], circ;
int pai[MAXN];
bool visited[MAXN];

bool dfs(int u, int p) {
    visited[u] = true;
    pai[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            circ.push_back(v);
            while (u != v) {
                circ.push_back(u);
                u = pai[u];
            }
            circ.push_back(v);
            return true;
        }
        if (dfs(v, u)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i= 0; i <m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) {
            reverse(circ.begin(), circ.end());
            cout << circ.size() << "\n";
            for (int x : circ) cout << x << " ";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}