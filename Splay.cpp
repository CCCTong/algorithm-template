#include <bits/stdc++.h>
#define lch tree[x].ch[0]
#define rch tree[x].ch[1]
using namespace std;
const int maxn = 1e6 + 10;
struct node {
    int val,ch[2],k,rev,fa;
    void init(int x){val = x;ch[0]=ch[1]=fa=rev=0;k=1;}
}tree[maxn];
int tot,root;
void update(int x){
    if (x == 0) return;
    tree[x].k = tree[lch].k + tree[rch].k + 1;
}
void pushdown(int x){
    if (x == 0) return;
    if (tree[x].rev){
        tree[lch].rev ^= 1; tree[rch].rev ^= 1;
        tree[x].rev = 0; swap(lch, rch);
    }
}
inline bool son(int x){
    return tree[tree[x].fa].ch[1] == x;
}
void join(int x,int y,int c){
    tree[x].ch[c] = y;
    tree[y].fa = x;
}
void rot(int x){
    int fa = tree[x].fa,gfa = tree[fa].fa,c = son(x);
    join(gfa, x, son(fa));
    join(fa, tree[x].ch[!c], c);
    join(x, fa, !c);
    update(fa); update(x);
}
void splay(int x,int f){
    pushdown(x);
    if (f == 0) root = x;
    while (tree[x].fa != f) {
        if (tree[tree[x].fa].fa == f) {rot(x); break;}
        if (son(x) == son(tree[x].fa)) {rot(tree[x].fa); rot(x); }
        else {rot(x); rot(x);}
    }
    update(x);
}
int build(int l,int r){
    if (l > r) return 0;
    int x = ++tot;
    int mid = (l + r) >> 1;
    tree[x].init(mid);
    lch = build(l,mid-1);
    rch = build(mid+1, r);
    tree[lch].fa = tree[rch].fa = x; update(x);
    return x;
}
int find(int x,int y){
    pushdown(x);
    if (tree[lch].k + 1 < y) return find(rch,y-1-tree[lch].k);
    else if (tree[lch].k + 1 == y) return x;
    else return find(lch,y);
}
void dfs(int x,int n){
    pushdown(x);
    if (lch) dfs(lch,n);
    if (1<= tree[x].val && tree[x].val <= n) printf("%d ",tree[x].val);
    if (rch) dfs(rch,n);
}
int main(){
    int n,m,l,r;
    // cout << 1 << endl;
    scanf("%d%d",&n,&m);
    tree[0].val = tree[n].val = 0x7f;
    root = build(0, n+1);
    while (m--) {
        scanf("%d%d",&l,&r);
        int a = find(root,l),b = find(root,r+2); // l-1 is l  and r+1 is r+2;
        splay(a, 0); splay(b, a); update(root);
        tree[tree[b].ch[0]].rev ^= 1;
        update(a); update(b); update(tree[b].ch[0]);
    }
    dfs(root,n);
    return 0;
}

