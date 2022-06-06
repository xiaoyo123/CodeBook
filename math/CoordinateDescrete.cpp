vector<int> a, b;

void solve(){
    a.resize(n); b.resize(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    sort(a.begin(), a.end());
    // a.erase(unique(a.begin(), a.end()), a.end());
    for(int i = 0; i < n; i++)
        b[i] = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    // b為離散化後的數組
}