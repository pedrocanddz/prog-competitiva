#include <bits/stdc++.h>

using namespace std;

long long findDigit(long long k) {
    long long digitCount = 1;

    while (digitCount * ((long long)pow(10, digitCount - 1)) * 9 < k) {
        k -= digitCount * ((long long)pow(10, digitCount - 1)) * 9;
        digitCount++;
    }

    long long number = ((long long)pow(10, digitCount - 1)) + (k - 1) / digitCount;
    string numberStr = to_string(number);
    long long result = (long long)numberStr[(k - 1) % digitCount] - '0';

    return result;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
       long long k;
        cin >> k;
        cout << findDigit(k) << "\n";
    }

    return 0;
}