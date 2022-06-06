#define MXN
#define ll

const ll p = 75577;
const ll MOD = 998244353;

ll Hash[MXN];
void build(string &s){
    ll val = 0;
    for(int i = 0; i < s.length(); i++){
        val = (val * p + s[i]) % MOD;
        Hash[i + 1] = val;
    }
}
int getHash(int L, int R){
    return (Hash[R + 1] - (Hash[L] * mPow(p, R - L + 1)) % MOD + MOD) % MOD;
}