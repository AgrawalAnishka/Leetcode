class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<char, int> mp;
    string output = "";
    bool solve(int i, string& s, string& target, int tight) {
        if (i >= s.size()) {

            return tight == 1;
        }

        char limit = tight == 1 ? 'a' : target[i];

        for (char ch = limit; ch <= 'z'; ch++) {
            if (!mp.count(ch))
                continue;
            mp[ch]--;
            
            if(mp[ch]==0) mp.erase(ch);

            int newTight = tight || ch > target[i];
            bool possible = solve(i + 1, s, target, newTight);

            mp[ch]++;
            if (possible) {
                return true;
            }
        }
        return false;
    }
    void buildAns(int i, string s, string target, int tight) {
        if (i >= s.size()) {
            return;
        }

        char limit = tight == 1 ? 'a' : target[i];
        for (char ch = limit; ch <= 'z'; ch++) {

            if (!mp.count(ch))
                continue;
            mp[ch]--;
            if(mp[ch]==0) mp.erase(ch);
            output.push_back(ch);

            int newTight = tight || ch > target[i];

            if (solve(i + 1, s, target, newTight)) {
                buildAns(i + 1, s, target, newTight);
                return;
            }
            output.pop_back();
            mp[ch]++;
        }
    }
    string lexGreaterPermutation(string s, string target) {
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        buildAns(0, s, target, 0);
       
        return output;
    }
};