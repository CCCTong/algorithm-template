#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m[105],a[105],lcm=1;
int exgcd(int a,int b,int &x,int &y){//扩欧
    if(!b){x=1,y=0;return a;}
    int re=exgcd(b,a%b,x,y),tmp=x;
    x=y,y=tmp-(a/b)*y;
    return re;
}
int work(){
    int i,j,d,x,y,re=0;
    for(i=1;i<=n;i++)lcm=lcm*m[i];//因为互质所以直接这么写了
    for(i=1;i<=n;i++){
        int kl=lcm/m[i];
        d=exgcd(kl,m[i],x,y);
        x=(x%m[i]+m[i])%m[i];
        re=(re+a[i]*x*kl)%lcm;
    }
    return re;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&m[i],&a[i]);;
    printf("%d",work());
    return 0;
}

// exCRT 扩展中国剩余定理
// 方程的合并，exgcd求一个解

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
LL c[maxn],m[maxn];
LL lcm = 1,n;
LL exgcd(LL a,LL b,LL &x,LL &y){
    if (b == 0) {x = 1; y = 0; return a;}
    LL gcd = exgcd(b, a%b, x, y),temp = x;
    x = y; y = temp - (a/b)*y;
    return gcd;
}
LL gcd(LL a,LL b){
    if (b == 0) return a;
    return gcd(b, a%b);
}
//int CRT(){
//    int x,y,ans = 0;
//    for (int i=1; i<=n; i++) lcm *= m[i];
//    for (int i=1; i<=n; i++) {
//        int now = lcm / m[i];
//        exgcd(now, m[i], x, y);
//        x = (x % m[i] + m[i]) % m[i];
//        ans = (ans + now*a[i]*x) % lcm;
//    }
//    return ans;
//}
LL inv(LL a,LL b){
    LL x,y;
    exgcd(a, b, x, y);
    if (x < 0)
        x = (x % b + b) % b;
    return x;
}
LL Mul(LL n, LL k,LL mod){
    LL ans = 0;
    while(k){
        if(k & 1) ans = (ans + n) % mod;
        k >>= 1;
        n = (n + n) % mod;
    }
    return ans;
}
int main(){
    freopen("/Users/chutong/in.txt", "r", stdin);
    int tag = 1;
    scanf("%lld",&n);
    for (int i=1; i<=n; i++)
        scanf("%lld%lld",&m[i],&c[i]);
    for (int i=2; i<=n; i++) {
        LL m1 = m[i-1],m2 = m[i],c2 = c[i],c1 = c[i-1],GCD = gcd(m1, m2);
        if ( (c2-c1) % GCD != 0) { tag = 0; break;}
        //  m[i] = m1*m2/GCD;
        c[i] = Mul( (c2-c1)/GCD,  inv(m1/GCD, m2/GCD), (m2/GCD)) * m1 + c1;
        //    c[i] = inv(m1/GCD, m2/GCD) * (c2-c1)/GCD % (m2/GCD) * m1 + c1;
        c[i] = (c[i] % m[i] + m[i]) % m[i];
    }
    if (tag == 1) cout << c[n] << endl;
    else cout << -1 << endl;
    return 0;
}

