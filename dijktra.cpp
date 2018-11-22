#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> pi;
const int maxn = 1e5+10;
const int maxx = 2500000;
struct node {
    int to,nex,w;
}edge[maxx];
int head[maxn];
LL dis[maxn];
int cnt,n,m,u,v,w,s;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48); ch=getchar();}
    return x*f;
}
void add(int u,int v,int w){
    edge[cnt] = (node){v,head[u],w};
    head[u] = cnt++;
}
void dijkstra(int s,LL dis[]){
    priority_queue<pi,vector<pi>,greater<pi> > pq;
    for(int i=1;i<=n;i++)dis[i] = LLONG_MAX; dis[s] = 0;
    pq.push(pi(0,s));
    while (!pq.empty()) {
        pi now = pq.top();pq.pop();
        int u = now.second;
        if (now.first > dis[u]) continue;
        for (int i=head[u]; ~i; i=edge[i].nex) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w){
                dis[v] = dis[u] + edge[i].w;
                pq.push(pi(dis[v],v));
            }
        }
    }
}
int main(){
    n = read(); m = read(); s = read();
    memset(head, -1, sizeof(head));
    for (int i=0; i<m; i++) {
        u = read(); v = read(); w = read();
        add(u, v, w);
    }
    dijkstra(s, dis);
    for (int i=1; i<=n; i++) {
        printf("%lld ",dis[i]);
    }
    printf("\n");
    return 0;
}

