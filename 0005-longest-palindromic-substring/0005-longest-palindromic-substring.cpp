class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (i == j)
                    dp[i][j] = true;
                else if (j == i + 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (dp[i][j]) {
                    if (ans.size() < j - i + 1) {
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};