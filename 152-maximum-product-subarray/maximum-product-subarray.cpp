class Solution {
public:
int ans  =INT_MIN;
int suff = 1;
int pref = 1;
    int maxProduct(vector<int>& nums) {
        for(int i  =0 ;i < nums.size() ; i++){
            if(suff==0) suff=1 ;
            if(pref==0) pref=1;

            pref*=nums[i];
            suff*=nums[nums.size() - i-1];

            ans= max({ans ,  pref , suff});
                 
            
        }
        return ans ;
    }
};