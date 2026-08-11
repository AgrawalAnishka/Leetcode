class Solution {
public:
vector<vector<int>> dp ;
vector<int> prefix ;
    int solve(vector<int>& nums, int l, int r) {

        if(l == r)
            return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];

        int ans = 0;
        int sum = 0;

        for(int i = l; i < r; i++) {

            sum += nums[i];

            int left = prefix[i+1]-prefix[l];
            int right = prefix[r+1] - prefix[i+1];

            if(left < right) {
                ans = max(ans,
                          left + solve(nums, l, i));
            }
            else if(right < left) {
                ans = max(ans,
                          right + solve(nums, i + 1, r));
            }
            else {
                ans = max({
                    ans,
                    left + solve(nums, l, i),
                    right + solve(nums, i + 1, r)
                });
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& nums) {
        int sum = 0;
        prefix.push_back(0);
        for(int i =0 ;i < nums.size() ; i++){

            sum += nums[i];
           prefix.push_back(sum);
        }
        dp.assign(nums.size() +1 , vector<int> (nums.size()+1 , -1)) ;

        return solve(nums, 0, nums.size() - 1);
    }
};