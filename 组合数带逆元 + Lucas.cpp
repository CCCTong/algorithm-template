LL qpow(LL a, LL b){
    LL ans = 1, base = a;
    while (b) {
        if (b & 1) {
            ans *= a;
        }
        base *= base;
        b >>= 1;
    }
    return ans;
}
//LL C(LL n,LL m){
//    LL ans = 1;
//    int j = 1;
//    for (int i=m-n+1; i<=m; i++,j++) {
//        ans = ((i*inv[j])%mod * ans)%mod;
//    }
//    return ans;
//}
LL C(LL n,LL m){
    if (m > n)
        return 0;
    return  fac[n] * qpow(fac[m] * fac[n-m], p-2) % mod;
}
LL Lucae(LL a,LL b){
    if (a < mod && b < mod)
        return C(a,b);
    return C(a % mod, b % mod) * Lucae(a / mod , b / mod);
}
