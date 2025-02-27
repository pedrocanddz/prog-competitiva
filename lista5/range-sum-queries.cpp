#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

using namespace std;

vector<ll> prefix(MAXN);


int main(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }   
    while (q--) {
        int a, b; cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << '\n';
    }

    return 0;
}