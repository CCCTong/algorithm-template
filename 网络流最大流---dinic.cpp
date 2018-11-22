#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e6;
const int inf = 1e9;
struct edge {
    int to, next;
    int c, f;  // c: capacity  f: flow
} edge[maxn];
int head[maxn],dep[maxn];
int n,m,s,t,tot;
bool bfs() {
    memset(dep, 0, sizeof(dep));
    queue<int> q;
    q.push(s);
    dep[s] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if(!dep[v] && edge[i].c > edge[i].f) {
                dep[v] = dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[t] != 0;
}

int dfs(int u, int cpflow) {  // cpflow: can pass flow  到达u点最大能通过的流量
    if(u == t) return cpflow;  // 到达汇点
    int addflow = 0;  // u 点到其他点 最多能增广的流量， 最多不能超过cpflow，由前面的边限制
    for(int i = head[u]; i != -1 && addflow < cpflow; i = edge[i].next){
        int v = edge[i].to;
        if(dep[u]+1 == dep[v] && edge[i].c > edge[i].f) {
            // 这一条路上增广的流量
            int tmpadd = dfs(v, min(cpflow-addflow, edge[i].c-edge[i].f));
            edge[i].f += tmpadd;  // 正向通过的流量加
            edge[i^1].f -= tmpadd;  // 反向的流量就得减
            addflow += tmpadd;
        }
    }
    return addflow;  // 返回这个点都汇点能增广的流量
}

int dinic() {
    int maxflow = 0;
    while(bfs())
        maxflow += dfs(s, inf);
    return maxflow;
}
void add(int u, int v, int c, int i) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].c = c;
    edge[tot].f = 0;
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].next = head[v];
    edge[tot].c = 0;
    edge[tot].f = 0;
    head[v] = tot++;
    // 正向边下标通过异或就得到反向边下标, 2 ^ 1 == 3 ; 3 ^ 1 == 2
}

void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}
int main() {
    scanf("%d%d%d%d",&n,&m,&s,&t);
    init();
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w, i);
    }
    int ans = dinic();
    printf("%d\n",ans);
    return 0;
}

