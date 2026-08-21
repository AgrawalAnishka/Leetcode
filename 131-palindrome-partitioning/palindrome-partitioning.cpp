class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<string>> ans;
    vector<string> output;
    void solve(string s, int start) {
        if (start >= s.size()) {
            ans.push_back(output);
            return;
        }
        for (int i = start; i < s.size(); i++) {

            if (dp[start][i]) {
                string temp = s.substr(start, i - start + 1);
                output.push_back(temp);
                solve(s, i + 1);
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dp.resize(s.size() + 1, vector<int>(s.size() + 1, -1));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (i == j)
                    dp[i][j] = true;
               else if (j == i + 1 && s[i] == s[j])
                    dp[i][j] = true;
                else {
                    dp[i][j] = s[i] == s[j] & dp[i + 1][j - 1];
                }
            }
        }

        solve(s, 0);
        return ans;
    }
};