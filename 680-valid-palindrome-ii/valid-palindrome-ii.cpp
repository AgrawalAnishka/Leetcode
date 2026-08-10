class Solution {
public:
    bool solve(int s , int e , string &  st ){
        int i  =s ;
        int j =e;

        while(i<j){
            if(st[i]!=st[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        bool change = false;

        int i =0 ;
        int j = s.size()-1 ;

        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;

            }else{
                if(change){
                    return false;
                }else{
                    change = true;
                    if(solve(i+1 , j , s)){
                        i++;
                    }
                    else if(solve(i , j-1  , s)){
                        j--;
                    }else{
                        // cout<<i<<" "<<j<< endl;
                        return false;
                    }
                  
                }
            }
        }
        return true;
    }
};