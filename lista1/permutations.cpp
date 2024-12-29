#include <bits/stdc++.h>

using namespace std;
vector<int> par, impar;

int main(){
    int n;
    cin >> n;
    if(n == 2 || n == 3){
        cout << "NO SOLUTION\n";
        return 0;
    }
    for(int i = 1 ; i <= n; i++){
        if(i % 2 == 0)
            par.push_back(i);
        else
            impar.push_back(i);
    }
    sort(par.begin(), par.end());
    sort(impar.begin(), impar.end());

    for(int i = 0; i < par.size(); i++)
        cout << par[i] << " ";
    for(int i = 0; i < impar.size(); i++)
        cout << impar[i] << " ";
    return 0;
}