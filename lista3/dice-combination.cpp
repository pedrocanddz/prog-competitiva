#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

vector<int> dp(MAXN + 1, 0);

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++)
            if (i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % (int)(1e9 + 7);
            
    cout << dp[n] << endl;

    return 0;
}
