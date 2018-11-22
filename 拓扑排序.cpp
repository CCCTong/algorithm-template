#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5  + 10;
queue<int> ans;
struct node{
    int to,nex,w;
}edge[maxn*10];
int in[maxn],head[maxn];
int n,cnt;
void init(){
    memset(head, -1, sizeof(head));
    memset(in, -1, sizeof(in));
}
void add(int u,int v,int w){
    edge[i].to = v;
    edge[i].w  = w;
    edge[i].nex = head[u];
    head[u] = cnt++;
}
void topsort(){
    int flag = 1;
    queue<int> q;
    while (!q.empty()) {
        for (int i=1; i<=n; i++) {
            if (in[i] == 0){
                q.push(i); ans.push(i);
                in[i]--;
            }
        }
        if (q.empty()) break;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i=head[u]; ~i; i=edge[i].nex) {
                int v = edge[i].to;
                if (in[v] == -1) {flag = 0; break;}
                else in[v]--;
            }
            if (!flag) break;
        }
        if (!flag) break;
    }
    if (ans.size() < n){
        flag = 0; return;
    }
}
int main(){

    return 0;
}

