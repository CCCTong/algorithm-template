#include <bits/stdc++.h>
using namespace std;
struct node {
    ll id,val;
}d[maxn];
bool cmp(const node &a,const node &b){
    return a.val==b.val? a.id < b.id : a.val < b.val;
}
void build(int n){
    len = sqrt(n);
    num = n % len;
    if (n % len) num++;
    for (int i=1; i<=n; i++) {
        be[i] = (i-1)*len+1;
        d[i].val = a[i];
        d[i].id = i;
    }
    for (int i=1; i<=num; i++) {
        l[i] = (i-1)*len+1;
        r[i] = i*len;
    }
    r[num] = n;
    for (int i=1; i<=n; i++) {
        sort(d+l[i],d+r[i]+1,cmp);
    }
}
void update(int L,int R,int c)
{
    if(be[L]==be[R])
    {
        for(int i=L;i<=R;i++)
            a[i]+=c;
        for(ll i=l[be[L]];i<=r[be[L]];i++){
            d[i].val = a[i];
            d[i].id = i;
        }
        sort(d+l[be[L]],d+r[be[L]]+1,cmp);
    }
    else
    {
        for(int i=L;i<=r[be[L]];i++)
            a[i]+=c;
        for(ll i=l[be[L]];i<=r[be[L]];i++){
            d[i].val = a[i];
            d[i].id = i;
        }
        sort(d+l[be[L]],d+r[be[L]]+1,cmp);
        for(ll i=l[be[R]];i<=R;i++)
            a[i]+=c;
        for(ll i=l[be[R]];i<=r[be[R]];i++){
            d[i].val = a[i];
            d[i].id = i;
        }
        sort(d+l[be[R]],d+r[be[R]]+1,cmp);
        for(ll i=be[L]+1;i<=be[R]-1;i++)
        {
            p[i]+=c;
        }
    }
}
