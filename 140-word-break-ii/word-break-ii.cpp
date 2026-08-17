class Solution {
public:
    vector<int> dp;
    vector<string> ans;
    string output;
    int maxLen = 0;
    unordered_map<string, bool> mp;
    bool solve(string& s, int start) {
        if (start >= s.size())
            return true;
        if (dp[start] != -1)
            return dp[start];
        bool ans = false;
        for (int i = start; i < s.size(); i++) {
            if (i - start + 1 > maxLen)
                continue;
            string temp = s.substr(start, i - start + 1);
            if (mp[temp]) {
                // output.push_back(temp+ ' ');
                ans = ans | solve(s, i + 1);
            }
        }
        return dp[start] = ans;
    }
    void formAns(string& s, int start) {
        if (start == s.size()) {
            ans.push_back(output);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (i - start + 1 > maxLen)
                continue;
            string temp = s.substr(start, i - start + 1);
            if (mp[temp] && solve(s, i + 1)) {
                int oldSize = output.size();

                if (output.empty())
                    output += temp;
                else
                    output += " " + temp;

                formAns(s, i + 1);

                output.resize(oldSize);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& nums) {
        dp.resize(s.size() + 1, -1);

        for (auto s : nums) {
            mp[s] = true;
            maxLen = max(maxLen, (int)s.size());
        }
        formAns(s, 0);

        return ans;
    }
};