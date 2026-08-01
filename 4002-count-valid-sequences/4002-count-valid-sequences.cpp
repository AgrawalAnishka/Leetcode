class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    void precompute(int N) {
        fact.resize(N + 1);
        invFact.resize(N + 1);

        fact[0] = 1;
        for (int i = 1; i <= N; i++)
            fact[i] = (fact[i - 1] * i) % MOD;

        invFact[N] = power(fact[N], MOD - 2);

        for (int i = N - 1; i >= 0; i--)
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;

        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    int countValidSequences(int n, int k) {
        precompute(n);

        long long total = C(n - 1, k - 1);

        long long odd = 0;
        if ((n - k) % 2 == 0) {
            int m = (n - k) / 2;
            odd = C(m + k - 1, k - 1);
        }

        return (total - odd + MOD) % MOD;
    }
};