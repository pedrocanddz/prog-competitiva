#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long totalCodes = 1LL << n;

    for (long long i = 0; i < totalCodes; i++) {
        long long grayCode = i ^ (i >> 1);
        bitset<20> binary(grayCode);
        string grayString = binary.to_string().substr(20 - n);
        cout << grayString << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1; // Number of test cases
    // cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}