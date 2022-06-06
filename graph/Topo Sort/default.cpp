#define MXN

int deg[MXN];
vector<int> graph[MXN];
vector<int> ans;
queue<int> q;

void build(){
    for(int i = 0, u, v; i < n - 1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        ++deg[v];
    }
    for(int i = 0; i < n; i++){
        if(!deg[i]) q.push(i);
    }
}
void bfs(){
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i : graph[u]){
            --deg[i];
            if(!deg[i]) q.push(i);
        }
        ans.push_back(u);
    }
    for(int i : ans) cout << i << " ";
    cout << endl;
}