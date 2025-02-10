#include <bits/stdc++.h>
#define MAXN 1005
#define pii pair<int, int>
#define endl "\n"

using namespace std;

char grid[MAXN][MAXN];
pii parent[MAXN][MAXN];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void bfs(int sx, int sy, int n, int m) {
    queue<pii> q;
    q.push({sx, sy});
    parent[sx][sy] = {-1, -1};

    while (!q.empty()) {
        pii p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        if (grid[x][y] == 'B') {
            string path;
            while (x != sx || y != sy) {
                int px = parent[x][y].first;
                int py = parent[x][y].second;
                for (int i = 0; i < 4; i++) {
                    if (px == x + dx[i] && py == y + dy[i]) {
                        path += dir[i];
                        break;
                    }
                }
                x = px, y = py;
            }
            
            cout << "YES\n" << path.size() << "\n";
            for(int i = path.size() - 1; i >= 0; --i)
                cout << path[i];
            
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && parent[nx][ny].first == 0) {
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    cout << "NO";
}

int main() {
    int n, m;
    cin >> n >> m;
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A'){
                sx = i;
                sy = j; 
            }
        }
    }
    bfs(sx, sy, n, m);
}