class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return -1;
        }

        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }

        if (nums.size() == k ) {
            // sort(nums.begin(), nums.end());
            // for (int i = 0; i < nums.size(); i++) {

            //     if (mp[nums[i]]<=1) {

            //         return nums[i];
            //     }
            // }
            return *max_element(nums.begin() , nums.end());

        } else if(k==1){
              sort(nums.rbegin(), nums.rend());
            for (int i = 0; i < nums.size(); i++) {

                if (mp[nums[i]]<=1) {

                    return nums[i];
                }
            }
            return -1;
        }else {
            
            if(mp[nums[0]] > 1 && mp[nums.back()] > 1) return -1; 
            if (mp[nums[0]]>1) {
                return nums.back();
            }
            if (mp[nums.back()]>1) {
                return nums[0];
            }
            return max(nums[0], nums.back());
        }
        return -1;
    }
};