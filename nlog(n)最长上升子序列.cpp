#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int num[maxn],dp[maxn];
int low(int l,int r,int val){
    while (l != r) {
        int mid = (l+r)>>1;
        if (dp[mid] >= val) r = mid;
        else  l = mid + 1;
    }
    return l;
}

int main(){
    int len = 1;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> num[i];
    dp[0] = num[0];
    for (int i=1; i<n; i++) {
        if (num[i] > dp[len-1]) {
            dp[len] = num[i];
            len++;
        }else{
            int x = low(0, len-1, num[i]);
            dp[x] = num[i];
        }
    }
    cout << len << endl;
    return 0;
}
