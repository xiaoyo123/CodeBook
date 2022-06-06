#define MXN;
int dp[MXN][MXN];

void solve(){
    string s, t;
    cin >> s >> t;

    int l1 = (int)s.length(), l2 = (int)t.length();

    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
}