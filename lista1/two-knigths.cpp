#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; ++k) {
        long long k2 = k *k;
        long long total = k2 * (k2 - 1) / 2;
        long long atk = 4 * (k - 1) * (k - 2);
        cout << total - atk << endl;
    }

    return 0;
}