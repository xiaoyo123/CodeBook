#define MXN

struct edge{
    int u, v, w;
    friend bool operator < (const edge &a, const edge &b){
        return a.w < b.w;
    }
};
edge graph[MXN];
int f[MXN];

void init(){
    for(int i = 0; i < MXN; i++) f[i] = i;
}
int find(int x){
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}
void merge(int x, int y){
    x = find(x), y = find(y);
    if(x != y) f[y] = x;
}
void solve(){
    init();
    for(int i = 0; i < m; i++)
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    sort(graph, graph + m);
    ll ans = 0;
    for(int i = 0; i < m; i++){
        if(find(graph[i].u) != find(graph[i].v)){
            merge(graph[i].u, graph[i].v);
            ans == graph[i].w;
        }
    }
    bool p = 1; // 判斷圖是否連通
    for(int i = 0; i < n; i++){
        if(find(0) != find(i)){
            p = 1; break;
        }
    }
    cout << (p ? ans : -1) << endl;
}