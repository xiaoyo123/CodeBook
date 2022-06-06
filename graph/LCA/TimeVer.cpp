#define MXN
#define LG

vector<int> graph[MXN];
int ti = 0, tin[MXN], tout[MXN], anc[MXN][LG], fa[MXN];

void dfs(int x, int f){
    fa[x] = f;
    tin[x] = ti++;
    for(int i : graph[x]){
        if(i == f) continue;
        dfs(i, x);
    }
    tout[x] = ti++;
}
bool IsAnc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int LCA(int u, int v){
    if(IsAnc(u, v)) return u;
    if(IsAnc(v, u)) return v;
    for(int i = LG - 1; i >= 0; i--){
        if(!IsAnc(anc[u][i], v)) u = anc[u][i];
    }
    return anc[u][0];
}

void build(){
    for(int i = 0, u, v; i < n - 1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 1);

    for(int i = 1; i <= n; i++) anc[i][0] = fa[i];

    for(int i = 1; i < LG; i++){
        for(int j = 1; j <= n; j++)
            anc[j][i] = anc[ans[j][i - 1]][i - 1];
    }
}