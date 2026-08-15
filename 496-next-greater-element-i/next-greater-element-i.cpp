class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        deque<int> q;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
      
            while (!q.empty() && q.back() < nums2[i]) {
                mp[q.back()] = nums2[i];
                q.pop_back();
            }
            
            q.push_back(nums2[i]);
        }
       
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            if(mp.find(nums1[i])==mp.end()) ans.push_back(-1);
            else ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};