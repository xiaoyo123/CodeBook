#define ll
#define MXN

const ll p1 = 75577, p2 = 20641, MOD = 998244353;
pair<ll, ll> Hash[MXN];

void build(string &s){
    ll v1 = 0, v2 = 0;
    for(int i = 0; i < s.length(); i++){
        v1 = (v1 * p1 + s[i]) % MOD;
        v2 = (v2 * p2 + s[i]) % MOD;
        Hash[i + 1].first = v1 % MOD;
        Hash[i + 1].second = v2 % MOD;
    }
}
pair<ll, ll> getHash(int i, int k){
    return make_pair((Hash[i + k].first - (Hash[i].first * mypow(p1, k)) % MOD + MOD) % MOD, 
        (Hash[i + k].second - (Hash[i].second * mypow(p2, k)) % MOD + MOD) % MOD);
}