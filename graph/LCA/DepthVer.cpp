#define MXN
#define LG

int dep[MXN], anc[MXN][LG], fa[MXN];
vector<int> graph[MXN];

void dfs(int x, int f, int s = 0){
    fa[x] = f;
    dep[x] = s;
    for(auto i : graph[x]){
        if(i == f) continue;
        dfs(i, x, s + 1);
    }
}
int LCA(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < LG; i++){
        if((dep[v] - dep[u]) >> i & 1) v = anc[v][i];
    }
    if(u == v) return u;
    for(int i = LG - 1; i >= 0; i--){
        if(anc[u][i] != anc[v][i]){
            u = anc[u][i];
            v = anc[v][i];
        }
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
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
    }
}