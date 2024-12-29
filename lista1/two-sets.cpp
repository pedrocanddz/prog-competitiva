#include <bits/stdc++.h>
using namespace std;
vector<int> set1, set2;

int main() {
    int n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    sum /= 2;
    while (n) {
        if (sum - n >= 0) {
            set1.push_back(n);
            sum -= n;
        } else {
            set2.push_back(n);
        }
        n--;
    }

    cout << set1.size() << endl;
    for (int num : set1) {
        cout << num << " ";
    }
    cout << endl;

    cout << set2.size() << endl;
    for (int num : set2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}