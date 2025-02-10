#include <bits/stdc++.h>

using namespace std;

int linear(vector<int>& arr, int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; ++i) {
        sum += arr[i];
    }
    return sum;
}

