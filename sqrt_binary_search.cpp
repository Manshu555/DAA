#include <bits/stdc++.h>
using namespace std;
long long sqrt_num(long long l, long long h, long long n) {
    long long mid = (l + h) / 2;
    if (mid * mid == n) return mid;
    if (h - l == 1) return l;
    if (mid * mid > n)
        return sqrt_num(l, mid, n);
    else
        return sqrt_num(mid, h, n);
}

int main() {
    long long n;
    cin >> n;
    cout << sqrt_num(0, n, n);
    return 0;
}
