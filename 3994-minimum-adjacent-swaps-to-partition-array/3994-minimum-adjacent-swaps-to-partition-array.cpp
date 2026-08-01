class Solution {
public:
    int MOD =1e9+7;
    long long res = 0;
    void mergeSort(vector<int>& nums, int l, int r, int mid) {

        vector<int> temp;
        int left = l;
        int right = mid + 1;

        while (left <= mid && right <= r) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;

            } else {
                res += (mid - left + 1);
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= r) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = l ;i <=r; i++){
            nums[i]= temp[i-l];
        }
    }
    void merge(vector<int>& nums, int s, int e) {
        if (s >=e)
            return ;
        int mid = s + (e - s) / 2;
        // int ans = 0;
       merge(nums, s, mid);
         merge(nums, mid + 1, e);

        mergeSort(nums, s, e, mid);

        return ;
    }
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        for (auto& i : nums) {
            if (i < a) {
                i = 0;
            } else if (i > b) {
                i = 2;
            } else {
                i = 1;
            }
        }
        merge(nums , 0 , nums.size()-1);
        return res%MOD;
    }
};