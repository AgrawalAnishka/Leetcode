class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        for (char c : word)
            mp[c]++;

        vector<int> freq;
        for (auto &it : mp)
            freq.push_back(it.second);

        sort(freq.rbegin(), freq.rend());

        int ans = 0;
        for (int i = 0; i < freq.size(); i++) {
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};