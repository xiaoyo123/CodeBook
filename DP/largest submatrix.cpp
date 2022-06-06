int mat[1005][1005];
int dpl[1005], dpr[1005];
int h[1005], L[1005], R[1005];

int solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    }

    memset(dpl, 0, sizeof(dpl));
    memset(dpr, 0, sizeof(dpr));
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    memset(h, 0, sizeof(h));
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mat[i][j]) dpl[j] = dpl[j - 1] + 1;
            else dpl[j] = 0;
        }
        for(int j = c; j >= 1; --j){
            if(mat[i][j]) dpr[j] = dpr[j + 1] + 1;
            else dpr[j] = 0;
        }
        for(int j = 1; j <= m; j++){
            if(mat[i][j]) h[j]++;
            else h[j] = 0;
        }
        for(int j = 1; j <= m; j++)
            L[j] = L[j] ? min(dpl[j], L[j]) : dpl[j];

        for(int j = 1; j <= m; j++)
            R[j] = R[j] ? min(dpr[j], R[j]) : dpr[j];

        for(int j = 1; j <= m; j++){
            ans = max(ans, (L[j] + R[j] - 1) * h[j]);
        }
    }
    return ans;
}
