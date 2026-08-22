class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0 ;
         int ctr = 0 ;
         int ans =0 ;
        for(int r =0 ; r< nums.size()  ;r++){
            if(nums[r]==0){
                ctr++;
            }
            while(ctr>k){
                if(nums[l]==0){
                    ctr--;
                }

                l++;

            }
            ans= max(ans , r-l+1);
        }
        return ans;
    }
};