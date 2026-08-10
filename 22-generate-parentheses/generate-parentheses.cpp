class Solution {
public:
vector<string> s ; 
string temp ; 
    void solve(int n , int open , int close){
        
        if(open<close ||open>n ||close> n ) return ;
        if(open==close && open==n) {
            s.push_back(temp);
        }

        temp.push_back('(');
        solve(n ,  open+1 , close);
        temp.pop_back();
        temp.push_back(')');
        solve(n ,  open , close+1);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        solve( n , 0  , 0);
        return s ;
    }
};