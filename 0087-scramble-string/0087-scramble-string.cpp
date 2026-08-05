class Solution {
public:
    unordered_map<string, bool> dp;

    bool check(string &s1, string &s2, int l1, int r1, int l2, int r2) {
        vector<int> freq(26, 0);

        for (int i = l1; i <= r1; i++)
            freq[s1[i] - 'a']++;

        for (int i = l2; i <= r2; i++)
            freq[s2[i] - 'a']--;

        for (int x : freq)
            if (x)
                return false;

        return true;
    }

    bool solve(string &s1, string &s2, int l1, int r1, int l2, int r2) {

        string key = to_string(l1) + "#" + to_string(l2) + "#" +
                     to_string(r1 - l1 + 1);

        if (dp.count(key))
            return dp[key];

        if (s1.substr(l1, r1 - l1 + 1) == s2.substr(l2, r2 - l2 + 1))
            return dp[key] = true;

        if (!check(s1, s2, l1, r1, l2, r2))
            return dp[key] = false;

        int len = r1 - l1 + 1;

        for (int k = 1; k < len; k++) {

            // No Swap
            bool noSwap =
                solve(s1, s2, l1, l1 + k - 1, l2, l2 + k - 1) &&
                solve(s1, s2, l1 + k, r1, l2 + k, r2);

            if (noSwap)
                return dp[key] = true;

            // Swap
            bool Swap =
                solve(s1, s2, l1, l1 + k - 1, r2 - k + 1, r2) &&
                solve(s1, s2, l1 + k, r1, l2, r2 - k);

            if (Swap)
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size())
            return false;

        return solve(s1, s2, 0, s1.size() - 1, 0, s2.size() - 1);
    }
};