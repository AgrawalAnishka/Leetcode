class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp ;
        unordered_map<char,int> mp2 ; 

        for(auto i : p){
            mp[i]++;

        }
        int l =0;
        vector<int> ans ;
         for(int r =0 ;r<s.size() ; r++){

            mp2[s[r]]++;
            while(r-l+1>=p.size() && mp2!=mp){
                mp2[s[l]]--;
                if(mp2[s[l]]==0){
                    mp2.erase(s[l]);
                }
                l++;
            }
            if(mp==mp2) ans.push_back(l);


         }
         return ans ;
    }
};