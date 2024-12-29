#include <bits/stdc++.h>

using namespace std;

int main(){
        
    string s;
    cin >> s;
    sort(s.begin(), s.end()); 
    set<string> ans;
    ans.insert(s);
    while(next_permutation(s.begin(), s.end())){
        ans.insert(s);
    }
    
    cout << ans.size() << endl;
    for (const string& x : ans) {
        cout << x << endl;
    }

    return 0;
}