
#include <bits/stdc++.h>
using namespace std;
int a[1000],c[1000];
int ans = 0;
void merge_sort(int l,int r){
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    int i = l ,j = mid + 1, k = l;
    while (i <= mid && j<=r) {
        if (a[i] <= a[j]){
            c[k++] = a[i++];
        }else{
            c[k++] = a[j++];
            ans += (mid - i + 1);
        }
    }
    while (i <= mid) c[k++] = a[i++];
    while (j <= r) c[k++] = a[j++];
    for (int i=l; i<=r; i++)
        a[i] = c[i];
}
int main(){
    int n = 10;
    for (int i=n-1; i>=0; i--) {
        cin >> a[i];
    }
    merge_sort(0, n-1);
    for (int i=0; i<n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
