fac[0] = 1;
for(int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % MOD;
inv[N] = MyPow(fac[N], MOD - 2);
for(int i = N - 1; i >= 0; i--)
    inv[i] = inv[i + 1] * (i + 1) % MOD;
Dem[2] = 1;
for(int i = 3; i <= N; i++)
    Dem[i] = (i * Dem[i - 1] % MOD + (i % 2 ? -1 : 1)) % MOD; 
// 算C(n, k) fac[n] * inv[k] % MOD * inv[n - k] % MOD;