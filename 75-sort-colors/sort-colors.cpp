class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1) return ;
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            while (i<nums.size() && nums[i] == 0) {
                i++;
            }
            while (j>=0 && (nums[j] == 2 || nums[j] == 1)) {
                j--;
            }
            if (i < nums.size() && j >= 0 && i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        cout<<"here"<<endl;
        j = nums.size()-1;

        while (i <= j) {
            while (i<nums.size() && (nums[i] == 1 || nums[i] == 0)) {
                i++;
            }
            while (j>=0 && nums[j] == 2) {
                j--;
            }
            if (i < nums.size() && j >= 0 && i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
    }
};