class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end() , [](auto a , auto b){
            return a[1]< b[1];
            
        });
        vector<int> temp = nums[0];
        int ctr = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i][0] < temp[1]) {
                ctr++;
            }else{

            temp =  nums[i];
            }
        }

        return ctr;
    }
};