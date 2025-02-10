#include <bits/stdc++.h>
#define MAXN 100005
#define endl "\n"
using namespace std;

vector<int> adj[MAXN], comp;
bool vis[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) 
        if (!vis[v]) dfs(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) 
        if (!vis[i]) {
            comp.push_back(i);
            dfs(i);
        }

    cout << comp.size() - 1 << endl;
    for (int i = 1; i < comp.size(); i++) 
        cout << comp[0] << " " << comp[i] << endl;

    return 0;
}