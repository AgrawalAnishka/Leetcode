class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>  ans ; 
        sort(nums.begin() , nums.end());
        if(nums.size()==0) return {};
        vector<int> temp = nums[0];
        vector<vector<int>> res ; 
        for(int i = 0; i <nums.size() ; i++){
                if(nums[i][0] > temp[1]){
                    ans.push_back(temp);
                    temp = nums[i];
                }else{
                    temp[1]  = max(temp[1] ,  nums[i][1]);
                }
            
        }
        ans.push_back(temp);

        return ans ;
    }
};