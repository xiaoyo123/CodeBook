#define MXN

int arr[MXN], dp[MXN];

void solve(){
    for(int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = arr[0];
    int now = 1;

    for(int i = 1; i < n; i++){
        if(dp[now - 1] < arr[i]) dp[now++] = arr[i];
        else{
            // *upper_bound(dp, dp + now, arr[i]) = arr[i]; 嚴格遞增
            *lower_bound(dp, dp + now, arr[i]) = arr[i];
        }
    }
    cout << now << endl;
}