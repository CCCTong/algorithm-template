#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 10;
int vis[maxn],pre[maxn],ans[maxn];
LL mon[2][maxn];
int n,m,Q;
int cnt1, cnt2;
vector<pair<int, int>> vec[maxn];
struct que{
    int x,y;
}q[maxn];
struct edge{
    int to,nex,w1,w2;
}edge[maxn],redge[maxn];
int head[maxn],rhead[maxn];
void add(int u,int v,int w1,int w2){
    edge[cnt1].to = v;
    edge[cnt1].w1 = w1;
    edge[cnt1].w2 = w2;
    edge[cnt1].nex = head[u];
    head[u] = cnt1++;
    redge[cnt2].to = u;
    redge[cnt2].w1 = w2;
    redge[cnt2].w2 = w1;
    redge[cnt2].nex = rhead[v];
    rhead[v] = cnt2++;
}
void init(){
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    memset(vis, -1, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    memset(mon, 0, sizeof(mon));
    for (int i=0; i<n; i++) {
        vec[i].clear();
    }
}
int find(int x){
    if (pre[x] == x){
        return x;
    }
    return find(pre[x]);
}
void LCA(int u,int v){
    vis[u] = 1;
    pre[u] = u;
    for (int i=head[u]; ~i; i=edge[i].nex) {
        if (edge[i].to != v)
            LCA(edge[i].to, u);
    }
    for (int i=rhead[u]; ~i; i=redge[i].nex) {
        if (redge[i].to != v){
            LCA(redge[i].to, u);
        }
    }
    for (int i=0; i<vec[u].size(); i++) {
        int re = vec[u][i].first;
        if (vis[re] == -1) continue;
        else ans[vec[u][i].second] = find(re);
    }
    pre[u] = find(v);
}
int main(){
    int T,u,v,w1,w2;
    scanf("%d",&T);
    while (T--) {
        LL sum = 0;
        scanf("%d",&n);
        init();
        for (int i=0; i<n-1; i++) {
            scanf("%d%d%d%d",&u,&v,&w1,&w2);
            sum += w1 + w2;
            add(u, v, w1, w2);
        }
        scanf("%d",&Q);
        for (int i=0; i<Q; i++) {
            scanf("%d%d",&q[i].x,&q[i].y);
            vec[q[i].x].push_back(make_pair(q[i].y, i));
            vec[q[i].y].push_back(make_pair(q[i].x, i));
        }
        LCA(1, 1);
        for (int i=0; i<n; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// 并查集 + tarjan 求LCA
