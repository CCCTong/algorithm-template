#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n,m;
int is_prime(int n){
    if (n == 2 || n == 3) return 1;
    if (n < 2 || (n % 6 != 1 && n % 6 != 5)) return 0;
    for(int i = 5; i * i <= n; i += 6)
        if( n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
}
int main(){
    int n,m,now;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        scanf("%d",&now);
        if (is_prime(now)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

