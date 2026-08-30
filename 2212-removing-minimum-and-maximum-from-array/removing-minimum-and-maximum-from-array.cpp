class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini  = 0;
        int maxi = 0;
        for(int i  =0 ;i < nums.size() ; i++){
            if(nums[mini] >  nums[i]){
                mini = i ;
            }
            if(nums[maxi] <= nums[i]){
                maxi = i ;
            }
        }

        int case1 = max(mini , maxi)+1;
        int case2 = nums.size() - min(mini , maxi);

        int case3 = min(mini , maxi)+1 + nums.size()-max(mini , maxi);

        return min({case1, case2, case3});
    }
};