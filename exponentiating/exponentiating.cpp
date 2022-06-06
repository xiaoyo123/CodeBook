#define MOD

int pow(int a, int b){
    int ret = 1;
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}