#include <bits/stdc++.h>
#define MAXN 20
#define MAXW 1e9
using namespace std;


const int INF = 1e9;

int dp[MAXN][MAXN];
int weight[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        sum += weight[i];
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i - 1]) {
                dp[i][j] = min(dp[i][j], abs(sum - 2 * j));
                dp[i][j] = min(dp[i][j], dp[i - 1][j - weight[i - 1]]);
            }
        }
    }

    cout << dp[n][sum / 2] << endl;

    return 0;
}