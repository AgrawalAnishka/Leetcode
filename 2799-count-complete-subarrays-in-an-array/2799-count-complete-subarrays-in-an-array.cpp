class Solution {
public:
int solve(vector<int> & nums , int k){
unordered_map<int, int> mp;
    int l =0 ;
    int ans = 0 ;

    for(int r =0 ;r<nums.size() ; r++){
        mp[nums[r]]++;
        while(mp.size()>k) { 
            mp[nums[l]]--;
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            l++;

        }
        ans+=r-l+1;
    }
    return ans ;
}
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s ; 
        for(int i  =0 ;i < nums.size() ; i++){
            s.insert(nums[i]);
        }
        int k = s.size();
        return solve(nums, k ) -solve(nums , k-1);
    }
};