void tarjan(int u){
    dfn[u] = low[u] = ++cnt;
    s.insert(u); st.push(u); vis[u] = 1;
    for (int i = head[u]; ~i; i=edge[i].nex) {
        if (!vis[u]){
            tarjan(edge[i].to);
            low[u] = min(low[u],low[edge[i].to]);
        }else if (s.count(u)){
            low[u] = min(low[u],dfn[edge[i].to]);
        }
    }
    if (dfn[u] == low[u]) {
        while (!st.empty()) {
            cout << s.top() << ' ';
            s.pop();
        }
    }
}
void tarjan(int u){
    dfn[u] = low[u] = ++tot;
    st[k++] = u; vis[u] = 1;
    for (int i=head[u]; ~i; i=edge[i].nex) {
        int v = edge[i].nex;
        if (!dfn[u]){
            tarjan(v);
            low[u] = min(low[u],low[edge[i].id]);
        }else if (vis[edge[i].id]) low[u] = min(low[u],dfn[edge[i].id]);
    }
    if (dfn[u] == low[u]) ans++;
}
// 记得枚举每一条边tarjan可能枚举不完。
