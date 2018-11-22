#include <bits/stdc++.h>
using namespace std;
const int maxn =  11000000+10;
int p[maxn<<2];
char s[maxn<<2],str[maxn];
int manacher(int len){
    int id = 0,ans = 0,maxx = 0;
    for (int i=1; i<len; i++) {
        if (maxx > i) p[i] = min(maxx-i,p[id*2-i]);
        else p[i] = 1;
        while( s[i-p[i]] == s[i+p[i]]) p[i]++;
        if (p[i] + i > maxx) {maxx = p[i] + i;id = i;}
        ans = max (ans,p[i]);
    }
    return ans-1;
}
int main(){
    scanf("%s",str);
    int len = (int)strlen(str),tot = 0;
    s[tot++] = '!'; s[tot++] = '#';
    for (int i=0; i<len; i++) {
        s[tot++] = str[i];
        s[tot++] = '#';
    }
    printf("%d\n",manacher(tot));
    return 0;
}
