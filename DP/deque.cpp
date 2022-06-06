#define MXN

int arr[MXN], dp[MXN];

void solve(){
    for(int i = 0; i < n; i++) cin >> arr[i];

    deque<pair<int, ll>> d;

    for(int i = 0; i < k; i++){
        dp[i] = d.empty() || d.back().second > 0 ? arr[i] : d.back().second + arr[i];
        while(d.size() && d.front().second >= dp[i])
            d.pop_front();
        d.push_front({i, dp[i]});
    }
    for(int i = k; i < n; i++){
        while(d.size() && d.back().first < i - k)
            d.pop_back();
        dp[i] = d.back().second + arr[i];
        while(d.size() && d.front().second >= dp[i])
            d.pop_front();
        d.push_front({i, dp[i]});
    }
}