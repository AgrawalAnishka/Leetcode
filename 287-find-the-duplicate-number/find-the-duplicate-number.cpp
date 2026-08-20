class Solution {
public:

    int findDuplicate(vector<int>& nums) {
    

        for(int i =0 ;i < nums.size() ; i++){
           

            int ac = abs(nums[i]);
            if(nums[ac]<0){
                return ac;
            }else{
                nums[ac] = -nums[ac];
            }


            
        }

        return -1; 
    }
};