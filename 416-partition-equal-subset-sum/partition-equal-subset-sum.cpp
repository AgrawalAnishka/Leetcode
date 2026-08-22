class Solution {
public:

vector<vector<int>> dp;

int solve(vector<int> & nums, int  i , int target){
    if(target==0) return true;
    if(target<0 || i >=nums.size()) return false;

    if(dp[i][target] != -1) return dp[i][target] ; 

    return dp[i][target] = solve(nums, i+1 , target) || solve(nums ,  i+1, target-nums[i]);
}
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int i =0 ;i <  nums.size() ; i++){
            sum+= nums[i];

        }

        if(sum%2) return false;
        dp.resize(nums.size()+1 , vector<int> ((sum/2)+1, -1));

        return solve(nums, 0 ,  sum/2);
    }
};