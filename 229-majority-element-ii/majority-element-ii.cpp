class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ctr1 = 0, e1 = INT_MIN;
        int ctr2 = 0, e2 = INT_MIN;

        for (int i : nums) {
            if (ctr1 == 0 && e2 != i) {
                e1 = i;
                ctr1++;
            }
            else if (ctr2 == 0 && e1 != i) {
                e2 = i;
                ctr2++;
            }
            else if (e1 == i) {
                ctr1++;
            }
            else if (e2 == i) {       // FIX
                ctr2++;
            }
            else {
                ctr1--;
                ctr2--;
            }
        }

        vector<int> ans;
        int c1 = 0, c2 = 0;

        for (int i : nums) {
            if (i == e1) c1++;
            if (i == e2) c2++;
        }

        int n = nums.size();

        if (c1 > n / 3) ans.push_back(e1);
        if (c2 > n / 3) ans.push_back(e2);

        return ans;
    }
};