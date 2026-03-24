class Solution {
public:
    using ll = long long;
    // extended gcd
    ll egcd(ll a, ll b, ll &x, ll &y) {
        if (b == 0) { x = 1; y = 0; return a; }
        ll x1, y1;
        ll g = egcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }

    ll inv_mod(ll a, ll mod) {
        ll x, y;
        ll g = egcd(a, mod, x, y);
        if (g != 1) return -1;              // inverse does not exist
        x %= mod;
        if (x < 0) x += mod;
        return x;
    }

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        const int MOD = 12345;
        // prime factors of 12345
        const int p1 = 3, p2 = 5, p3 = 823;

        int total = n * m;
        vector<ll> a(total);
        for (int i = 0, k = 0; i < n; ++i)
            for (int j = 0; j < m; ++j, ++k)
                a[k] = grid[i][j];

        auto solve_for_prime = [&](int P) -> vector<ll> {
            vector<ll> pref(total), suf(total);
            pref[0] = a[0] % P;
            for (int i = 1; i < total; ++i)
                pref[i] = (pref[i-1] * (a[i] % P)) % P;

            suf[total-1] = a[total-1] % P;
            for (int i = total-2; i >= 0; --i)
                suf[i] = (suf[i+1] * (a[i] % P)) % P;

            vector<ll> res(total);
            for (int i = 0; i < total; ++i) {
                ll left  = (i == 0) ? 1 : pref[i-1];
                ll right = (i == total-1) ? 1 : suf[i+1];
                res[i] = (left * right) % P;
            }
            return res;
        };

        vector<ll> r1 = solve_for_prime(p1);
        vector<ll> r2 = solve_for_prime(p2);
        vector<ll> r3 = solve_for_prime(p3);

        // Precompute CRT constants for MOD = 3 * 5 * 823
        ll M1 = MOD / p1;          // 4115
        ll M2 = MOD / p2;          // 2469
        ll M3 = MOD / p3;          // 15
        ll inv1 = inv_mod(M1 % p1, p1);  // inverse of 4115 mod 3
        ll inv2 = inv_mod(M2 % p2, p2);  // inverse of 2469 mod 5
        ll inv3 = inv_mod(M3 % p3, p3);  // inverse of 15 mod 823

        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0, k = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j, ++k) {
                ll t1 = (r1[k] * inv1) % p1;
                ll t2 = (r2[k] * inv2) % p2;
                ll t3 = (r3[k] * inv3) % p3;

                ll x = 0;
                x = (x + t1 * M1) % MOD;
                x = (x + t2 * M2) % MOD;
                x = (x + t3 * M3) % MOD;

                ans[i][j] = (int)x;
            }
        }
        return ans;
    }
};
