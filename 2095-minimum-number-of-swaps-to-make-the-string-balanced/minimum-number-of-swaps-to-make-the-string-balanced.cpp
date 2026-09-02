class Solution {
public:
    // int solve(int i , int open , int close)
    int minSwaps(string s) {
        int open = 0; 
        int close =0 ;
        int ctr =0 ;
        for(int i =0 ; i < s.size() ; i++){
            if(s[i]=='['){
                open++;
            }else{
                close++;
            }

            if(close> open){
                
                ctr = max(ctr ,  close-open);
            }
        }
        cout<<ctr<<endl;
        int ans = ctr/2;
        if(ctr%2){
            ans++;
        }
        return ans ;
    }
};