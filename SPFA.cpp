#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int vis[maxn],head[maxn],dis[maxn],cnt[maxn];
int n,m,tot;
struct node { int to,nex,w; }edge[maxn];
void add(int u,int v,int w){ edge[tot] = (node){v,head[u],w}; head[u] = tot++; }
int spfa(int s){
    queue<int> q; q.push(s);
    for (int i=0;i<=n;i++) dis[i] = INT_MAX; dis[s] = 0;
    while (!q.empty()) {
        int u = q.front();q.pop(); vis[u] = 0;
        for (int i=head[u]; ~i; i=edge[i].nex) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w) {
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return 1;
                dis[v] = dis[u] + edge[i].w;
                if (!vis[v]) { vis[v] = 1; q.push(v); }
            }
        }
    }
    return 0;
}
void init(){
    memset(head, -1, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    tot = 0;
}
int main(){
    int t,u,v,w;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m); init();
        for (int i=0; i<m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            add(u, v, w);
            if (w >= 0) add(v, u, w);
        }
        if (spfa(1)) puts("YE5");
        else puts("N0");
    }
    return 0;
}

