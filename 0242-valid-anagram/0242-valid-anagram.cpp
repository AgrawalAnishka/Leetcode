class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> nums(27 , 0);

        for(int i =0 ;i < s.size() ; i++){
            nums[s[i]-'a']++;
        }
         for(int i =0 ;i < t.size() ; i++){
            nums[t[i]-'a']--;
        }

        for(int i  =0 ; i <26; i ++){
            if(nums[i]!=0){
                return false;
            }
        }
        return true;
    }
};