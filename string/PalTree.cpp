typedef long long LL;

// next[state][c]表示state在兩邊添加字符c以後變成的回文串的編號（和字典樹類似)
// state[i]以第i個字元為結尾的最長回文
// len[state[i]] 求出第i個state的長度
// num[state[i]] 某個回文有幾個回文後綴 ababa->aba->a
// cnt[state[i]] state[i]有幾個

const int MXN = 200000 + 10;
struct PalT{
    int nxt[MXN][26],fail[MXN],len[MXN]; 
    int tot, lst, n, state[MXN], cnt[MXN], num[MXN];
    int diff[MXN], sfail[MXN], fac[MXN], dp[MXN];
    char s[MXN] = {-1};
    int newNode(int l, int f){
      len[tot] = l, fail[tot] = f, cnt[tot] = num[tot] = 0;
      memset(nxt[tot], 0, sizeof(nxt[tot]));
      diff[tot] = (l > 0 ? l - len[f] : 0);
      sfail[tot] = (l > 0 && diff[tot] == diff[f] ? sfail[f] : f);
      return tot++;
    }
    int getfail(int x){
        while(s[n-len[x] - 1] != s[n]) x = fail[x];
        return x;
    }
    int getmin(int v){
    	dp[v] = fac[n - len[sfail[v]] - diff[v]];
    	if(diff[v] == diff[fail[v]])
            dp[v] = min(dp[v], dp[fail[v]]);
        return dp[v] + 1;
    }
    int push(){
        int c = s[n] - 'a', np = getfail(lst);
        if(!(lst = nxt[np][c])){
          lst = newNode(len[np] + 2, nxt[getfail(fail[np])][c]);
          nxt[np][c] = lst; num[lst] = num[fail[lst]] + 1;
        }
        fac[n] = n;
        for(int v = lst; len[v] > 0; v = sfail[v])
            fac[n] = min(fac[n], getmin(v));
        return ++cnt[lst], lst;
    }
    void init(string _s){
        tot = lst = n = 0;
        newNode(0, 1), newNode(-1, 1);
        for(; _s[n];) s[n + 1] = _s[n], ++n, state[n - 1] = push();
        for(int i = tot - 1; i > 1; i--) cnt[fail[i]] += cnt[i];
    }
}a, b;