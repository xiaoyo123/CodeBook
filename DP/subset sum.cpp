#define MXN

int cnt[MXN];
bitset<100010> dp;

void solve(){
    int sum = 0;
    for(int i = 0, a; i < n; i++){
        cin >> a;
        sum += a;
        cnt[a]++;
    }
    dp = 1;
    for(int i = 0; i <= sum; i++){
        if(num[i]){
            for(int j = 0; (i << j) <= cnt[i]; j++){
                dp |= (dp << (i << j));
                cnt[i] -= (1 << j);
            }
            dp |= (dp << (i * cnt[i]));
        }
    }
}