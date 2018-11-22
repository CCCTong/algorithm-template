#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 10;
LL sum[maxn<<2],p[maxn<<2];
LL sum1,num[maxn];
void up(int id){
    sum[id] = sum[id<<1] + sum[id<<1|1];
}
void down(int l,int r,int id){
    int mid = (l + r) >> 1;
    if (p[id]){
        p[id<<1] += p[id];
        p[id<<1|1] += p[id];
        sum[id<<1] += p[id]*(mid-l+1);
        sum[id<<1|1] += p[id]*(r-mid);
        p[id] = 0;
    }
}
void build(int l,int r,int id){
    if (l == r){
        sum[id] = num[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r ,id<<1|1);
    up(id);
}
void rev(int l,int r,int id,int L,int R,int c){
    if (L <= l && r <= R){
        p[id] += c;
        sum[id] += (r - l + 1) * c;
        return ;
    }
    int mid = (l + r) >> 1;
    down(l, r, id);
    if (L <= mid) rev(l, mid, id<<1, L, R, c);
    if (R > mid) rev(mid+1, r, id<<1|1, L, R, c);
    up(id);
}
void query(int l,int r,int id,int L,int R){
    if (L <= l && r <= R){
        sum1 += sum[id];
        return;
    }
    int mid = (l + r) >> 1;
    down(l,r,id);
    if (L <= mid) query(l, mid, id<<1, L, R);
    if (R > mid) query(mid+1, r, id<<1|1, L, R);
}
