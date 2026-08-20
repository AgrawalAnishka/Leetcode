class Solution {
public:
vector<int> dp;
bool solve(int i , vector<int> & nums){
    if(i== nums.size()-1) return true;
    if(i>=nums.size()) return false;
    if(dp[i]!=-1) return dp[i];
    bool ans  = false ;
    for(int j =1; j<= nums[i] ; j++){
       ans =ans  | solve(i +j ,  nums);
       if(ans) break;
    }
    return dp[i] = ans ; 
}
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size()+1  ,-1);
        return solve( 0 , nums);
    }
};