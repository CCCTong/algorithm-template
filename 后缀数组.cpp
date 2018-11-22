#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char s[maxn];
int y[maxn],x[maxn],c[maxn],sa[maxn],rk[maxn],h[maxn];
int n,m;
void get_sa(){
    for (int i=1; i<=n; i++) c[x[i] = s[i]]++;
    for (int i=2; i<=m; i++) c[i] += c[i-1];
    for (int i=n; i>=1; i--) sa[c[x[i]]--] = i;
    for (int i=1; i<=n; i <<= 1) {
        int num = 0;
        for (int k=n-i+1; k<=n; k++) y[++num] = k;
        for (int k=1; k<=n; k++)
            if (sa[k] > i) y[++num] = sa[k] - i;
        for (int k=1; k<=m; k++) c[k] = 0;
        for (int k=1; k<=n; k++) c[x[k]]++;
        for (int k=2; k<=m; k++)  c[k] += c[k-1];
        for (int k=n; k>=1; k--) { sa[c[x[y[k]]]--] = y[k]; y[k]= 0;}
        swap(x, y); x[sa[1]] = 1; num = 1;
        for (int k=2; k<=n; k++) {
            if (y[sa[k-1]] == y[sa[k]] && y[sa[k]+i] == y[sa[k-1]+i])
                x[sa[k]] = num;
            else x[sa[k]] = ++num;
        }
        if (num == n) break; m = num;
    }
}
void get_h(){
    int k = 0;
    for (int i=1; i<=n; i++) {
        rk[sa[i]] = i;
    }
    for (int i=1; i<=n; i++) {
        if (rk[i] == 1) continue;
        if (k != 0) k--;
        int j = sa[rk[i]-1];
        while (j+k<=n && i+k<=n && s[i+k]==s[j+k]) ++k;
        h[rk[i]] = k;
    }
}
int main(){
    scanf("%s",s+1);
    n = (int)strlen(s+1);m = 122;
    get_sa();
    for (int i=1; i<=n; i++) {
        printf("%d ",sa[i]);
    }
    cout << endl;
    return 0;
}
