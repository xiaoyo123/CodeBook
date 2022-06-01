#define N (int)1e5
#define sq sqrt(N)

struct mo{
    int id, l, r;
};
mo query[N];
int res = 0;
int ans[N];

bool cmp(mo a, mo b){
    if(a.l / sq == b.l / sq) return a.r < b.r;
    return a.l / sq < b.l / sq;
}
void add(int x){/*...*/}
void sub(int x){/*...*/}
void solve(){
    sort(query, query + N, cmp);
    for(int i = 1, l = 1, r = 0; i <= q; i++){
        while(l > query[i].l) add(--l);
        while(r < query[i].r) add(++r);
        while(l < query[i].l) sub(l++);
        while(r > query[i].r) sub(r--);
        ans[query[i].id] = res;
    }
}