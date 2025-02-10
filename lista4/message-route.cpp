#include <bits/stdc++.h>
#define MAXN 100005
#define endl "\n"
using namespace std;

vector<int> adj[MAXN];
int parent[MAXN];
bool vis[MAXN];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) 
            if (!vis[v]) {
                vis[v] = true;
                parent[v] = u;
                q.push(v);
            }
    }
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

    bfs(1);
    if (!vis[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;
    for (int v = n; v != 0; v = parent[v]) 
        path.push_back(v);
    
    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--) 
        cout << path[i] << " ";

    return 0;
}