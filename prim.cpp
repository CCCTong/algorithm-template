#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2005;
ll G[maxn][maxn],dis[maxn],m[maxn][maxn];
ll vis[maxn],pre[maxn];
void init(int n){
    for (int i=2; i<=n; i++) {
        dis[i] = G[1][i];
        pre[i] = 1;
    }
}
ll find(int n,ll *val){
    ll ans = 0;
    for (int j=1; j<=n; j++) {
        if (!vis[j] && *val > dis[j]) {
            *val = dis[j]; ans = j;// break;
        }
    }
    return ans;
}
ll prim(int n){
    ll ans = 0;
    pre[1] = 0; dis[1] = 0; vis[1] = 1;
    for (int i=2; i<=n; i++) {
        ll val = LLONG_MAX;
        ll x = find(n, &val);
        vis[x] = 1;
        ans += dis[x];
        m[x][pre[x]] = m[pre[x]][x] = 1;
        for (int j=1; j<=n; j++) {
            if (!vis[j] && dis[j] > G[x][j]) {
                dis[j] = G[x][j];
                pre[j] = x;
            }
        }
    }
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) {
                G[i][j] = 0;
            }else{
                G[i][j] = LLONG_MAX;
            }
        }
    }
    int l,r; ll v;
    while (m--) {
        scanf("%d%d%lld",&l,&r,&v);
        G[l][r] = G[r][l] = v;
    }
    return 0;
}
