class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int I : nums) {
            mp[I]++;
        }

        int I = 1;

        while (true) {
            if (mp.find(I * k) == mp.end()) {
                return k * I;
            }
            I++;
        }
        return -1;
        }
    };