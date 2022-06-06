#define MXN

vector<int> graph[MXN], path;

void dfs(int x){
    while(!graph[x].empty()){
        int u = graph[x].back();
        graph[x].pop_back();
        dfs(u);
    }
    path.push_back(x);
}
void build(){
    for(int i = 0, u, v; i < n - 1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    
    for(auto i : path) cout << i << " ";
    cout << endl;
}