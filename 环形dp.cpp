#include <bits/stdc++.h>
using namespace std;
const long long inf = 9999999999;
const int maxn = 1005;
long long dp[maxn][maxn],sum[maxn],val[maxn];
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> val[i];
        val[i+n] = val[i];
    }
    for (int i=1; i<=2*n; i++) {
        sum[i] = sum[i-1] + val[i];
    }
    for (int j=2; j<=2*n; j++) {
        for (int i=j-1; i>0 && j-i<n; i--) {
            dp[i][j] = inf;
            for (int k=i; k<j; k++) {
                dp[i][j] = min(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1], dp[i][j]);
            }
        }
    }
    long long ans = inf;
    for (int i=1; i<=n; i++) {
        if (dp[i][i+n-1] < ans) {
            ans = dp[i][i+n-1];
        }
    }
    cout << ans << endl;
    return 0;
}
