#include <bits/stdc++.h>
using namespace std;

set<string> permutations;


void permute(string &s, int l, int r) {
    if (l == r) {
        permutations.insert(s);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

int main() {
    string s;
    cin >> s;

    permute(s, 0, s.size() - 1);

    cout << permutations.size() << endl;

    for (auto perm : permutations) 
        cout << perm << endl;

    return 0;
}
