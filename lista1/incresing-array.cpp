#include <bits/stdc++.h>
using namespace std;
vector<int> vec;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }

    long long moves = 0;
    for(int i = 1; i < n; i++){
        if(vec[i] < vec[i-1]){
            moves += vec[i-1] - vec[i];
            vec[i] = vec[i-1];
        }
    }

    cout << moves << "\n";
    return 0;
}