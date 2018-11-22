#include <bits/stdc++.h>
#define maxn 2005
#define MAX 2000000000
using namespace std;
typedef long long ll;
int n,m,pre[maxn];
struct node{
    int l,r;
    ll val;
}edge[200005];
int find(int x){
    if (pre[x] == x) {
        return x;
    }
    return pre[x] = find(pre[x]);
}
void join(int x,int y){
    int x1 = find(x);
    int y1 = find(y);
    pre[x1] = y1;
}
bool same(int x,int y){
    return find(x) == find(y);
}
bool cmp(node x,node y){
    return x.val < y.val;
}
ll kruskal(){
    ll ans = 0; int count = 0;
    for (int i=0; i<m; i++) {
        if (!same(edge[i].l, edge[i].r) && edge[i].val != MAX) {
            join(edge[i].l, edge[i].r);
            ans += edge[i].val; count++;
        }
    }
    if (count == n-1) {
        return ans;
    }else{
        return -1;
    }
}
int main(){
    int v,p;
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        scanf("%d%d%d%d",&edge[i].l,&edge[i].r,&v,&p);
        if (p == 1) {
            edge[i].val = v;
        }else if (p == 0){
            edge[i].val = MAX;
        }
    }
    for (int i=1; i<=n; i++) pre[i] = i;
    sort(edge, edge+m, cmp);
    ll vs = kruskal();
    if (vs == -1){
        printf("no\n");
    }else{
        printf("yes\n");
        printf("%lld\n",vs);
    }
    return 0;
}
