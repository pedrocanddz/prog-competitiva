#include <bits/stdc++.h>

using namespace std;
vector<int> lista;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        lista.push_back(x);
    }
    sort(lista.begin(), lista.end());
    for(int i = 0; i < n; i++)
        if(lista[i] != i+1){
            cout << i+1 << endl;
            return 0;
        }
    

    return 0;
}