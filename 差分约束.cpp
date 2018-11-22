#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[50][50],num[50];
void init(){
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<10; i++) {
        dp[1][i] = 1;
    }
    for (int i=2; i<20; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<10; k++) {
                if (abs(j-k) >= 2) {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
    }
}
ll solve(string s){
    ll ans = 0;
    for (int i=1; i<s.size(); i++)
        for (int j=1; j<10; j++)
            ans += dp[i][j];
    for (int i=1; i<s[0] - '0'; i++){
        ans += dp[s.size()][i];
    }
    for (int i=1; i<s.size(); i++) {
        for (int j=0; j<s[i]-'0'; j++) {
            if (abs(j - s[i-1] + '0') >= 2) {
                ans += dp[s.size() - i][j];
            }
        }
        if (abs(s[i-1] - s[i]) < 2) break;
        if (i == s.size() - 1) ans++;
    }
    if (s.size() == 1) ans++;
    return ans;
}
int main(){
    int flag = 0;
    init();
    string A,B;
    cin >> A >> B;
    ll ans = solve(B) - solve(A) ;
    for (int i=0; i<A.size()-1; i++) {
        if (abs(A[i+1] - A[i]) < 2) {
            flag = 1; break;
        }
    }
    !flag ? cout << ans + 1 << endl : cout << ans << endl;
    return 0;
}

