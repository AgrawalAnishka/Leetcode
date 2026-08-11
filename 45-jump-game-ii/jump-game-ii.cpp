class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& nums) {
        if (i == nums.size() - 1)
            return 0;

        if (i >= nums.size())
            return INT_MAX / 2;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX / 2;

        for (int j = 1; j <= nums[i]; j++) {
            ans = min(ans, solve(i + j, nums) + 1);
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return solve(0, nums);
    }
};