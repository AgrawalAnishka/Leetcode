class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxi(nums.size() , nums[0] );
        vector<int> mini(nums.size() ,  nums.back());
        // int maxi =0 ;
        for(int i =1 ;i < nums.size() ; i++){
            maxi[i] = max(maxi[i-1] ,nums[i]  );
        }

        for(int i = nums.size()-2 ; i >=0 ; i--){
            mini[i] = min(mini[i+1] , nums[i]);
        }

        for(int i  =0 ;i < maxi.size() ; i++){
            if(maxi[i]-mini[i]<=k){
                return i ;
            }
        }
        return -1;
    }
};