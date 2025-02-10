#include <bits/stdc++.h>
#define MAXN 1005
#define endl "\n"

using namespace std;

int n, m;
char matriz[MAXN][MAXN];
bool vis[MAXN][MAXN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && matriz[nx][ny] == '.')
            dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matriz[i][j];
    
    int count = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (matriz[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                count++;
            }
    cout << count;

    return 0;
}