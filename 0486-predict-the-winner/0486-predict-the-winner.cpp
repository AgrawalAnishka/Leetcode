class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, vector<int>& nums, int turn) {
        if (i > j) return 0;

        if (dp[i][j][turn] != -1) return dp[i][j][turn];

        if (turn == 1) {
            int case1 = solve(i + 1, j, nums, 0) + nums[i];
            int case2 = solve(i, j - 1, nums, 0) + nums[j];
            return dp[i][j][turn] = max(case1, case2);
        } else {
            int case1 = solve(i + 1, j, nums, 1) - nums[i];
            int case2 = solve(i, j - 1, nums, 1) - nums[j];
            return dp[i][j][turn] = min(case1, case2);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(2, -1)));

        int finalAns = solve(0, n - 1, nums, 1);
        return finalAns >= 0;
    }
};