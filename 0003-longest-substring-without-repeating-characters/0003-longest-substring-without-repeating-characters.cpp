class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp ; 
        int ans= 0;
        int l =0 ;
        for(int i =0 ;i <s.size() ; i ++){
            while(mp.find(s[i])!=mp.end()){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
           ans = max(ans , i-l+1);
           mp[s[i]]++;
        }
        return ans ;
    }
};