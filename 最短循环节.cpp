#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int nex[maxn];
char a[maxn];
void cal(int len){
    int k = 0; nex[0] = 0;
    for (int i=1; i<len; i++) {
        while (a[i] != a[k] && k) {
            k = nex[k-1];
        }
        if (a[i] == a[k])k++;
        nex[i] = k;
    }
}
int main(){
    int n,t;
    cin >> t;
    while (t--) {
        cin >> n;
        scanf("%s",a);
        cal(n);
        int len = n - nex[n-1];
        cout << len << endl;
        for (int i=0; i<len; i++) {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
