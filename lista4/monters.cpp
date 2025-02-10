#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
int monster_dist[1005][1005];
int player_dist[1005][1005];
pair<int,int> parent[1005][1005];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void multi_bfs(queue<pair<int,int>>& q, int dist[][1005]) {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && dist[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    queue<pair<int,int>> monsters;
    int px, py;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') monsters.push({i, j});
            if (grid[i][j] == 'A') px = i, py = j;
        }
    }

    multi_bfs(monsters, monster_dist);
    queue<pair<int,int>> player;
    player.push({px, py});
    player_dist[px][py] = 1;
    multi_bfs(player, player_dist);

    // Verificar bordas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || i == n-1 || j == 0 || j == m-1) && 
                player_dist[i][j] != 0 && (player_dist[i][j] < monster_dist[i][j] || monster_dist[i][j] == 0)) {
                cout << "YES\n" << player_dist[i][j] - 1;
                return 0;
            }
        }
    }
    cout << "NO";
}