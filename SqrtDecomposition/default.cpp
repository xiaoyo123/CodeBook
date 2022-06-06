struct blk{
    vector<int> local;
    int global;
    int tag;
    blk(){
        local.clear(); 
        tag = global = 0;
    }
};

vector<blk> arr;
int n, sq;

void build(){
    int sq = sqrt(n), num = (n + sq - 1) / sq;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        arr[i / sq].local.push_back(x);
        arr[i / sq].global += x;
    }
}
void updateQuery(int ql, int qr, int v){
    int bl = ql / sq, br = qr / sq, ret = 0;
    if(bl == br){
        for(int i = ql; i <= qr; i++)
            arr[bl].local[i % sq] += v;
        arr[bl].global += (qr - ql + 1) * v;
        return;
    }
    for(int i = ql; i < (bl + 1) * sq; i++){
        arr[bl].local[i % sq] += v;
        arr[bl].global += v;   
    }
    for(int i = bl + 1; i < br; i++){
        arr[i].tag += v;
        arr[i].global += v * sq;
    }
    for(int i = br * sq; i <= qr; i++){
        arr[br].local[i % sq] += v;
        arr[br].global += v;
    }
}
int query(int ql, int qr){
    int bl = ql / sq, br = qr / sq, ret = 0;
    if(bl == br){
        for(int i = ql; i <= qr; i++)
            ret += arr[bl].local[i % sq] + arr[bl].tag;
        return ret;
    }
    for(int i = ql; i < (bl + 1) * sq; i++)
        ret += arr[bl].local[i % sq] + arr[bl].tag;
    for(int i = bl + 1; i < br; i++)
        ret += arr[i].global;
    for(int i = br * sq; i <= qr; i++)
        ret += arr[br].local[i % sq] + arr[br].tag;
    return ret;
}