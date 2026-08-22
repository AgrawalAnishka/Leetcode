class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans  ; 
        sort(nums.begin() , nums.end());
        vector<int> temp = nums[0];

        for(int i  =1 ;i < nums.size() ; i++){
            if(temp[1] >=  nums[i][0]){
                temp[1] = max(temp[1] , nums[i][1]);
            }else{
                ans.push_back(temp);
                temp = nums[i];
            }
        }
        ans.push_back(temp);
        return ans ;
    }
};