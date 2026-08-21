class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res ; 
        for(int  mask = 0 ;mask < (1<<nums.size()) ; mask++){
            vector<int> output ; 

            for(int i  =0 ;i < nums.size() ; i++){
                if((1<<i) &  mask){
                    output.push_back(nums[i]);
                }
            }
            res.push_back(output);
        }

        return res;

    }
};