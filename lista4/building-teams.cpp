#include <bits/stdc++.h>
#define MAXN 100005
#define endl "\n"
using namespace std;

vector<int> adj[MAXN];
int cor[MAXN];
bool flag = true;

void dfs(int u, int c) {
    cor[u] = c;
    for (int v : adj[u]) {
        if (cor[v] == c) flag = false;
        if (cor[v] == 0) dfs(v, 3 - c);
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

    for (int i = 1; i <= n; i++)
        if (cor[i] == 0) dfs(i, 1);

    if (!flag) cout << "IMPOSSIBLE";
    else for (int i = 1; i <= n; i++) cout << cor[i] << " ";
    

    return 0;
}