#include <bits/stdc++.h>
#define MAXN 200005
#define MAXH 20 
#define ll long long
#define endl '\n'

using namespace std;

int heap[MAXN][MAXH];
vector<int> base(MAXN);

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
        cin >> heap[i][0];
    
    base[1] = 0;
    for (int i = 2; i < MAXN; ++i) 
        base[i] = base[i/2] + 1;
    
    for (int j = 1; j < MAXH; ++j)
        for (int i = 0; i + (1 << j) <= n; ++i)
            heap[i][j] = min(heap[i][j-1], heap[i+(1<<(j-1))][j-1]);
    
    while (q--) {
        int l, r; 
        cin >> l >> r;
        l--;
        r--;
        int k = base[r - l + 1];
        cout << min(heap[l][k], heap[r-(1<<k)+1][k]) << endl;
    }

    return 0;
}