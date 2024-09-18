// #include <bits/stdc++.h>
// using namespace std;
// long long sqrt_num(long long l, long long h, long long n) {
//     long long mid = (l + h) / 2;
//     if (mid * mid == n) return mid;
//     if (h - l == 1) return l;
//     if (mid * mid > n)
//         return sqrt_num(l, mid, n);
//     else
//         return sqrt_num(mid, h, n);
// }

// int main() {
//     long long n;
//     cin >> n;
//     cout << sqrt_num(0, n, n);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

double bs(double n){
    double l = 0;
    double h = n;
    while((h - l) > 1e-6){
        double mid = (l + h) / 2.0; 
        if (mid * mid > n) h = mid;
        else l = mid;
    }
    return (l + h) / 2.0; 
}

int main(){
    double n;
    cin >> n;
    cout <<setprecision(6) << bs(n);
    return 0;
}




