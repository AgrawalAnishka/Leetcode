class Solution {
public:
vector<int> dp;
    int solve(int i  , vector<int> & nums){
        if(i>=nums.size()) return 0 ;
        if(dp[i]!=-1) return dp[i];
        int case1 = solve(i+1 , nums);
        int case2 = solve(i+2 , nums) +nums[i];
        return dp[i] = max(case1, case2) ; 

    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1 , -1);
        return solve(0 , nums);
    }
};