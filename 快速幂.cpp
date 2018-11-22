#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL qpow(LL a,LL b,LL mod){
    LL ans = 1, base = a % mod;
    while (b) {
        if (b & 1) ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans % mod;
}
LL qpow(LL a, LL b){
    LL ans = 1, base = a;
    while (b) {
        if (b & 1) ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}
