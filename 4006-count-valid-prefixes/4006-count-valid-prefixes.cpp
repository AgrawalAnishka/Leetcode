class Solution {
public:
    int countValidPrefixes(string s) {
        int temp =0 ;
        int ans = 0; 
        for(auto ch : s){
            if(ch=='0'){
                temp++;
            }else{
                temp--;
            }
            
            if(temp>=-1 && temp<=1) ans++;
        }
        return ans ;
    }
};