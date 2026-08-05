class Solution {
public:
    int maxArea(vector<int>& nums) {
        int l =0 ;
        int r = nums.size()-1 ; 
        int ans =0 ;
        while(l<=r){
            // cout<< (r-l) * min(nums[r],nums[l]) << " ";
            ans = max(ans , (r-l) * min(nums[r],nums[l])  );
            if(nums[l]< nums[r]) {
                l++;
            }else {
                r--;
            }

            
        }
        return ans ;
    }
};