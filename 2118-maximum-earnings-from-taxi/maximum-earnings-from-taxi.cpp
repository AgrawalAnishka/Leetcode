class Solution {
public:
    vector<long long> dp;

    long long solve(int i, vector<vector<int>>& rides) {
        if (i >= rides.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];
        long long start = rides[i][0];
        long long end = rides[i][1];
        long long tip = rides[i][2];
        int next = lower_bound(rides.begin() + i + 1, rides.end(),
                               vector<int>{rides[i][1], 0, 0}) -
                   rides.begin();
        long long exclude = solve(i + 1, rides);
        long long include  = solve(next, rides) + end - start + tip;
        

        return dp[i] = max(include, exclude);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        dp.resize(rides.size() + 1, -1);
        sort(rides.begin(), rides.end());
        return solve(0, rides);
    }
};