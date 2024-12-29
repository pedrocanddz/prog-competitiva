#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

vector<int> dp(MAXN + 1, 0);

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    
    dp[0] = 1;
    for (int i = 1; i <= sum; i++)
        for (int c : coins)
            if (i - c >= 0)
                dp[i] = (dp[i] + dp[i - c]) % 1000000007;
            
    cout << dp[sum] << endl;

    return 0;
}
