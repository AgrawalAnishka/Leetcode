class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> temp1 ; 
        vector<int> temp2  ; 

        temp1.push_back(nums[0]);
        temp2.push_back(nums[1]); 



        for(int i  =2 ;i < nums.size() ; i++){
            if(temp1.back() >  temp2.back()){
                temp1.push_back(nums[i]);
            }else{
                temp2.push_back(nums[i]);

            }
        }
        vector<int> finalAns ; 
        for(int i : temp1){
            finalAns.push_back(i);

        }

        for(auto i :  temp2){
            finalAns.push_back(i);
        }
        return finalAns ; 
    }
};