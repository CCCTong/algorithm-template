#include <bits/stdc++.h>
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long LL;
int gcd(int a,int b){if (b == 0) return a; return gcd(b , a%b);}
int lcm(int a, int b){ return a/gcd(a,b)*b;}
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48); ch=getchar();}
    return x*f;
}
const int maxn = 100;
int cap[maxn],flow[maxn],pre[maxn],A[maxn],B[maxn];
int bfs(int s,int t){
    queue<int> q;
    memset(pre,-1,sizeof(pre));
    pre[s] = 0; flow[s] = INT_MAX;
    q.push(s);
    while(!q.empty()){
        int now = q.front(); q.pop();
        if (now == t) break;
        for (int i=1; i<=m; i++) {
            if (i != s && cap[now][i] > 0 && pre[i] == -1){
                pre[i] = now;
                flow[i] = min(flow[now], cap[now][i]);
                q.push(i);
            }
        }
    }
    if (pre[t] == -1) return -1;
    else return flow[t];
}
int maxflow(int s,int t){
    int add = 0,sum = 0;
    while(add = bfs(s,t) != -1){
        int now = t;
        while(now != s){
            int last = pre[now];
            cap[last][now] -= add;
            cap[now][last] += add;
            now = last;
        }
        sum += add;
    }
    return sum;
}
int main(){
    int n,m;
    sc2(n,m); 
    int s = 0, t = n+m+1;
    for (int i=1;i<=n;i++){
        sc1(A[i]); A[i] -= m;
    }
    for (int i=n+1;i<=m+n;i++){
        sc1(B[i]); B[i] -= n;
    }
    for (int i=1; i<=n; i++) {
        for (int j=n+1; j<=n+m; j++) {
            cap[i][j] = min(A[i],B[j]);
        }
    }
    int max_flow = maxflow(s,t);
    if (max_flow == 0) printf("No\n");
    else{
        for (int i=1; i<=n; i++) {
            for (int j=n+1; j<=n+m; j++) {
                printf("%d ",cap[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}


