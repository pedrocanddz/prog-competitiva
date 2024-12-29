#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int current = i;
        while (current > 0) {
            int digit = current % 10;
            current /= 10;
            if (digit > 0) 
                dp[i] = min(dp[i], dp[i - digit] + 1);
        }
    }

    cout << dp[n] << endl;
    return 0;
}