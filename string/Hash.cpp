const ll p1 = 44497, p2 = 23209, mod = 998244353;
string s;
pll hsh[100005];

void build(){
    ll v1 = 0, v2 = 0;
    fill(hsh, hsh + (int)s.length() + 5, make_pair(0, 0));
    for(int i = 0; i < (int)s.length(); i++){
        v1 = (v1 * p1 + s[i]) % mod;
        v2 = (v2 * p2 + s[i]) % mod;
        hsh[i + 1].first = v1 % mod;
        hsh[i + 1].second = v2 % mod;
    }
}

ll mypow(ll x, ll y){
    ll ans = 1;
    for(; y > 0; y >>= 1){
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
    }
    return ans;
}

pll getHash(int i, int k){
    return make_pair((hsh[i + k].first - (hsh[i].first * mypow(p1, k)) % mod + mod) % mod, 
        (hsh[i + k].second - (hsh[i].second * mypow(p2, k)) % mod + mod) % mod);
}