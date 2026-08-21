class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int ctr =0 ; 
        for(auto ch : s){
            if(ch>='0' && ch<='9') continue;
            else ctr++;
        }
        vector<string> res;
        for(int mask = 0 ; mask < (1<<ctr) ; mask++){
            string temp = s ; 
            int j =ctr-1;
            for(int i  = 0 ;i < s.size() ; i ++){
                if(isalpha(s[i]) ){
                      if(mask&(1<< j)){
                      
                        temp[i] = (toupper(s[i]));
                    }else{
                        temp[i] = (tolower(s[i]));
                    }
                      j--;
                }
            }
            res.push_back(temp);
        }
        return res ;
    }
};