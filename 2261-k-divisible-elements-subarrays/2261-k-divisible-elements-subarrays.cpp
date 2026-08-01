class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++) {
            int temp = 0;

            vector<int> res;

            for (int j = i; j < nums.size(); j++) {
                res.push_back(nums[j]);
                if (nums[j] % p == 0) {
                    temp++;
                   
                }
                 if (temp <= k) {

                        s.insert(res);
                    }
                    else break;
            }
        }
        return s.size();
    }
};