#define MXN

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
    f[y] = x == y ? f[y] : x;
}