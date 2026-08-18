class Solution {
public:
vector<vector<int>> dp;
int solve(vector<int> & nums , int i  , int buy){

    if(i>=nums.size() ) return  0 ;

    if(dp[i][buy] !=-1) return dp[i][buy]  ; 
    int case1 = solve(nums, i+1, buy);
    if(buy){
        int case2 = solve(nums , i+1 , 1-buy) - nums[i];
        return dp[i][buy] = max(case1 , case2);
    }else{
        int case2  = solve(nums , i+2 , 1-buy) +nums[i];
        return  dp[i][buy] =max(case1 ,  case2) ;
    }

}
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1, vector<int> ( 2 , -1)) ;
        return solve(prices , 0 , 1);
    }
};