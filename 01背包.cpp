#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int dp[maxn];
int v[105],w[105];
int main(){
    int n,m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> w[i] >> v[i];
    for (int i=1; i<=n; i++) {
        for (int j=m; j>0; j--) {
            if (j-w[i] >= 0) {
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
    }
    cout << M[m] << endl;
    return 0;
}

//完全背包
for (int i=1 ; i <n; i++){
    for (int j=1; j<=v; j++){
        for (int k=0; k*c[i] <=j;k++){
            if (c[i] <= j){
                f[i][j] = max(f[i-1][j],f[i-1][j-k*c[i]] + k*w[i]);
            }else{
                f[i][j] = f[i-1][j];
            }
        }
    }
}
// 多重背包
for (int i = 1; i <= 5; i++)
    for (int k = 1; k <= cot[i];k++)
        for (int j = 10; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
