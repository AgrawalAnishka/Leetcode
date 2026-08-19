class Solution {
public:
vector<vector<int>>dp;
int solve(int i , int j , string& s1, string& s2){
    if(i>=s1.size() || j>=s2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j] =  solve(i+1 ,  j+1, s1, s2) +1;
    }
    return dp[i][j] = max(solve(i+1 ,  j , s1, s2) ,  solve(i , j+1 ,  s1, s2));
}
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size()+1, vector<int> (text2.size()+1 , -1));
        return solve( 0, 0 , text1 ,  text2) ; 

    }
};