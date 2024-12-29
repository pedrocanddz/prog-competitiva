#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int count, maxCount;
    count = maxCount = 1;
    for(int i = 1; i < s.size(); i++)
        if(s[i] == s[i-1]){
            count++;
            maxCount = max(maxCount, count);
        }else{
            count = 1;
        }
    cout << maxCount << "\n";

    return 0;
}