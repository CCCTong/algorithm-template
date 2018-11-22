#include <bits/stdc++.h>
#define inf 9999999
using namespace std;
typedef pair<int, int> pi;
const int maxn = 1005;
const int maxm = 1e5+10;
int n,m,k,s,t,cont,cnt,u,v,w;
int dis[maxn],head[maxn],rhead[maxm],vis[maxn];
struct edg {
    int to,nex,w;
}edge[maxm],redge[maxm];
struct node {
    int f,g,id;
    bool operator < (const node& now)const{
        return now.f == f ? now.g < g : now.f < f;
    }
};
void init(){
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
}
void add(int u,int v,int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].nex = head[u];
    head[u] = cnt++;
    redge[cont].to = u;
    redge[cont].w = w;
    redge[cont].nex =  rhead[v];
    rhead[v] = cont++;
}
void dijskal(int t){
    for (int i=0; i<=n; i++) {
        dis[i] = inf;
    }
    dis[t] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, t));
    while (!pq.empty()) {
        pi u = pq.top(); pq.pop();
        int id = u.second;
        for (int i=rhead[id]; ~i; i=redge[i].nex) {
            int v = redge[i].to;
            if (dis[v] > dis[id] + redge[i].w) {
                dis[v] = dis[id] + redge[i].w;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
}
int a_star(){
    priority_queue<node> pq;
    if (dis[s] == inf) return -1;
    if (s == t) k++;
    node root;
    root.id = s; root.g = 0; root.f = dis[s];
    pq.push(root);
    int cnt = 0;
    while (!pq.empty()) {
        node now = pq.top(); pq.pop();
        if (now.id == t) cnt++;
        if (cnt == k) return now.g;
        for (int i=head[now.id]; ~i; i=edge[i].nex) {
            node nx; nx.id = edge[i].to;
            nx.g = edge[i].w + now.g;
            nx.f = nx.g + dis[nx.id];
            pq.push(nx);
        }
    }
    return -1;
}
int main(){
    init();
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&s,&t);
    for (int i=1; i<=m; i++) {
        scanf("%d%d%d",&u,&v,&w);
        add(u, v, w);
    }
    // spfa();
    dijskal(t);
    int ans = a_star();
    printf("%d\n",ans);
    return 0;
}
