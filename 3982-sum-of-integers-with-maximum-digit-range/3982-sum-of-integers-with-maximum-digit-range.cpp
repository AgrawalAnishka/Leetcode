class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
int ans =0;
        for (int I=0;I<nums.size();I++){
            string s = to_string(nums [I]);
            int maxi =0;
            int mini = INT_MAX;
            
            for(int j =0;j<s.size();j++){
                mini = min (mini, s[j]-'0');
maxi = max (maxi, s[j]-'0');

            }
mp[maxi-mini].push_back(nums[I]);
ans = max(ans, maxi-mini);
        }
        int sum =0;
        for(int I=0;I<mp[ans].size();I++){
            sum+=mp[ans][I];
        }
        return sum ;
    }
};