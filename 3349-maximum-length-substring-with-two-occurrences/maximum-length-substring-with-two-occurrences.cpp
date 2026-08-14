class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0; 
        int ans =0;
        unordered_map<int,int> mp;
        for(int r =0 ; r< s.size(); r++){
            mp[s[r]]++;
            while(mp[s[r]] > 2){
                mp[s[l]]--;
                l++;
            }
            ans = max( ans ,  r-l+1);
        }
        return ans;
    }
};