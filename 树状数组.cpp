
#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int tree[maxn],num[maxn];
int n,m;
int lowbit(int x){
    return x & (-x);
}
void rev_range(int l,int r,int v){
    while (l <= n) {
        tree[l] += v;
        l += lowbit(l);
    } r++;
    while (r <= n) {
        tree[r] -= v;
        r += lowbit(r);
    }
}
void rev_single(int x,int v){
    while (x <= n) {
        tree[x] += v;
        x += lowbit(x);
    }
}
int sum_range(int l,int r){
    int ans = 0;
    while (r > 0) {
        ans += tree[r];
        r -= lowbit(r);
    } l--;
    while (l > 0) {
        ans -= tree[l];
        l -= lowbit(l);
    }
    return ans;
}
int sum_single(int x){
    int ans = 0;
    while (x > 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main(){
    int opt,x,y,k;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        scanf("%d",&num[i]); rev_single(i, num[i] - num[i-1]);
    }
    for (int i=0; i<m; i++) {
        scanf("%d",&opt);
        if (opt == 1){
            scanf("%d%d%d",&x,&y,&k);
            rev_range(x, y, k);
        }else if (opt == 2) {
            scanf("%d",&x);
            printf("%d\n",sum_single(x));
        }
    }
    return 0;
}
