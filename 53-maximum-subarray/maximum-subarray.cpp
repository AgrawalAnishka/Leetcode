class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum =0 ;
        int maxi =INT_MIN;
        int ans  =INT_MIN;
        for(int i  =0 ;i <nums.size() ; i++){
            
            if(sum+nums[i]<=0){
               ans = max(ans , sum);
               sum =0 ; 
            }else{
                sum +=nums[i];
                
               ans = max(ans , sum);
            }
            maxi = max(maxi ,  nums[i]);
        }
        if(maxi<0) return maxi ;
        return max(sum , ans) ;
    }
};