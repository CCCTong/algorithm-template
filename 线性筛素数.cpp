#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
int a[maxn];
int n,m;
void prime(){
    for (int i=0; i<=n; i++) a[i] = 1; a[0] = a[1] = 0;
    for(int i=2;i<=n;i++){
        if (a[i] == 1)
            for (int j=2; j*i<=n; j++)
                a[i*j] = 0;
    }
}
int main(){
    int now;
    cin >> n >> m; prime();
    for (int i=0; i<m; i++) {
        scanf("%d",&now);
        if (a[now] == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

