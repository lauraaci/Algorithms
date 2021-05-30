#include <bits/stdc++.h>
using namespace std;
long long modexp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
        cout << res<<" "<<a<<endl;
    }
    return (res+m)%m;
}

