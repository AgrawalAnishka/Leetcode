class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {

        int m = nums.size();
        int n = nums[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (nums[0][0] == 1)
            return 0;

        dp[0][0] = 1;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (nums[r][c] == 1)
                    continue;

                if (r > 0)
                    dp[r][c] += dp[r - 1][c];

                if (c > 0)
                    dp[r][c] += dp[r][c - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};