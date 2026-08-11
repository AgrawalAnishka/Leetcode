class Solution {
public:
    vector<int> pre ; 
    vector<vector<int>> dp ; 
    int solve(vector<int> & nums , int l , int r){
        if(l>=r) return 0 ; 
        if(dp[l][r]!=-1) return dp[l][r];
        int case1 = pre[r+1]-pre[l+1] - solve(nums , l+1 ,  r);
        int case2  = pre[r] - pre[l] - solve(nums, l , r-1);
        return dp[l][r] = max(case1 , case2);
    }
    int stoneGameVII(vector<int>& stones) {
        pre.push_back(0);
        dp.assign(stones.size()+1 , vector<int>(stones.size()+1 , -1));
        int sum =0 ; 
        for(int i  =0 ; i<  stones.size() ; i++){
            sum+=stones[i];
            pre.push_back(sum);
        }

        return solve(stones , 0 , stones.size()-1);
    }
};