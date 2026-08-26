class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = s ;
        int l=0;
       int ctr =0 ;
        for(int r=0 ;r < s.size() ; r++){
            if(s[r]=='1'){
                ctr++;

            }
            while(ctr > k  ){
                if(s[l]=='1'){
                    ctr--;
                }
                l++;
            }
            while(ctr==k && s[l]=='0'){
                l++;
            }
            if(ctr==k && ans.size() > r-l+1) {
                ans = s.substr(l ,  r-l+1) ; 
            }

            if(ctr==k && ans.size()==r-l+1){
                ans = min(ans , s.substr(l , r-l+1));
            }
        }
        if(ctr!=k) return "";
        return ans ; 
    }
};