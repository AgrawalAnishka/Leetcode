class Solution {
public:
    vector<int> parent;
    // int findParent(int node){
    //     if(parent[node]!=-1){
    //         return parent[node];

    //     }
    //     return parent[node] =  findParent(parent[node]);

    // }
    int longestConsecutive(vector<int>& nums) {

        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]];
        }
        int ans = 0;
        for (auto & it : mp) {

            if (mp.find(it.first - 1) != mp.end()) {
               it.second = mp[it.first - 1] + 1;
                // ans = max(ans, it.second);
            } else {
               it.second = 1;
            }
        }
        for(auto it: mp){
            ans =max(ans , it.second);
        }
        return ans;
    }
};