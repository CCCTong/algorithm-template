#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char line[maxn],key[maxn];
int vis[maxn],tot,n;
struct node { node* nex[26]; node* fail; int sum,id; };
inline node* add(){
    node* now = (node *)malloc(sizeof(node));
    memset(now->nex, 0, sizeof(now->nex));
    now->sum = 0; now->fail = NULL;
    return now;
}
inline void insert(node* root,char s[]){
    node* now = root; int len = (int)strlen(s);
    for (int i=0; i<len; i++) {
        int id = s[i] - 'a';
        if (now->nex[id] == NULL)  now->nex[id] = add();
        now = now->nex[id];
    }
    now->sum++; now->id = ++tot;
}
void fail(node* root){
    queue<node* > q; q.push(root);
    while (!q.empty()) {
        node* now = q.front(); q.pop();
        for (int i=0; i<26; i++) if (now->nex[i] != NULL) {
            if (now == root) now->nex[i]->fail = root;
            else{
                node* nx = now->fail;
                while (nx != NULL) {
                    if (nx->nex[i] != NULL) {now->nex[i]->fail = nx->nex[i]; break;}
                    nx = nx->fail;
                }
                if (nx == NULL)  now->nex[i]->fail = root;
            }
            q.push(now->nex[i]);
        }
    }
}
int ac(char s[],node* root){
    node* now = root;
    int cnt = 0, len = (int)strlen(s);
    for (int i = 0; i<len; i++) {
        int id = s[i] - 'a';
        while (!now->nex[id] && now != root) now = now->fail;
        now = now->nex[id];
        if (now == NULL) now = root;
        node* nx = now;
        while (nx != root) {
            if (nx->sum > 0 && !vis[nx->id]) {cnt += nx->sum; vis[nx->id] = 1;}
            else break;
            nx = nx->fail;
        }
    }
    return cnt;
}
void del(node* now){
    if (now == NULL) return;
    for (int i=0; i<26; i++) del (now->nex[i]);
    delete now;
}
int main(){
    scanf("%d",&n); node* root = add();
    for (int i=0; i<n; i++) { scanf("%s",key); insert(root, key); }
    scanf("%s",line); fail(root);
    printf("%d\n",ac(line, root));
    return 0;
}


