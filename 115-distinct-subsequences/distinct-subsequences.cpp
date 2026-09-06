class Solution {
public:
vector<vector<int>> dp ; 
    int solve(string s, string t , int i , int j ){

        if( j>=t.size() ) return 1;
        if( (t.size()-j > s.size()-i )||i>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int case1=0;
        int case2 =  solve(s, t, i+1 ,  j ) ; 
        if(s[i]==t[j]){
             case1 = solve(s, t, i+1 , j+1)  ;
            
        }

        return dp[i][j] = case1+case2;

    }
    int numDistinct(string s, string t) {
        dp.resize(s.size()+1, vector<int>(t.size() +1 ,  -1));
        return solve(s , t, 0 ,0);
    }
};