#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll f[maxn],sum[maxn];
int q[maxn];
int n,m,p;
ll cal_f(int i,int j){
    return f[j]+(sum[i]-sum[j]+i-(j+1)-p)*(sum[i]-sum[j]+i-(j+1)-p);
}
ll cal_x(int i,int j){
    return 2*(sum[i]-sum[j]+i+1-(j+1));
}
ll cal_y(int i,int j){
    return (f[i]+(sum[i]+i+1)*(sum[i]+i+1))-(f[j]+(sum[j]+j+1)*(sum[j]+j+1));
}
int main(){
    int v;
    cin >> n >> p;
    for (int i=1; i<=n; i++) {
        cin >> v;
        sum[i] = sum[i-1] + v;
    }
    int l = 0, r = 0;
    q[r++] = 0;
    for (int i=1; i<=n; i++) {
        while (l+1 < r && cal_y(q[l+1], q[l]) <= (sum[i]+i-p)*cal_x(q[l+1], q[l]))
            l++;
        f[i] = cal_f(i, q[l]);
        while (l+1 < r && cal_y(i, q[r-1])*cal_x(q[r-1], q[r-2]) <= cal_y(q[r-1], q[r-2])*cal_x(i, q[r-1]))
            r--;
        q[r++] = i;
    }
    cout << f[n] << endl;
    return 0;
}
