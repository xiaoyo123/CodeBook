#define N (int)1e5

int bit[N];

void update(int x, int val){
    while(x <= N){
        bit[x] += val;
        x += (x & -x);
    }
}

int query(int x){
    int ans = 0;
    while(x){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}