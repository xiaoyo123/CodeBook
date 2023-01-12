struct LCA{
    int ti = 0, tin[MXN], tout[MXN], anc[MXN][LG], fa[MXN];
    void dfs(int x, int f){
        fa[x] = f;
        tin[x] = ti++;
        for(auto i : graph[x]){
            if(i == f) continue;
            dfs(i, x);
        }
        tout[x] = ti++;
    }
    bool IsAnc(int u, int v){
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int GetLca(int u, int v){
        if(IsAnc(u, v)) return u;
        if(IsAnc(v, u)) return v;
        for(int i = LG - 1; i >= 0; i--)
            if(!IsAnc(anc[u][i], v)) u = anc[u][i];
        return anc[u][0];
    }
    int dep[MXN], dis[MXN][LG];
    void dfs(int x, int f, int d = 0){
        fa[x] = f;
        dep[x] = s;
        for(auto i : graph[x]){
            if(i.first == f) continue;
            dis[i.first][0] = i.second;
            dfs(i.first, x, s + 1)
        }
    }
    int GetLca(int u, int v){
        if(dep[u] > dep[v]) swap(u, v);
        for(int i = 0; i < LG; i++)
            if((dep[v] - dep[u]) >> i & 1) v = anc[v][i];
        if(u == v) return u;
        for(int i = LG - 1; i >= 0; i--){
            if(anc[u][i] != anc[v][i]){
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        return anc[u][0];
    }
    int Getdis(int x, int Anc){
        int MAX = 0;
        for(int i = LG - 1; i >= 0; i--){
            if(dep[x] - (1 << i) >= dep[Anc]){
                MAX = max(MAX, dis[x][i]);
                x = anc[x][i];
            }
        }
        return MAX;
    }
    void build(){
        for(int i = 1; i <= n; i++)
            anc[i][0] = fa[i];
        for(int i = 1; i < LG; i++){
            for(int j = 1; j <= n; j++){
                anc[j][i] = anc[anc[j][i - 1]][i - 1];
                dis[j][i] = max(dis[j][i - 1], dis[anc[j][i - 1]][i - 1]);
            }
        }
    }
};