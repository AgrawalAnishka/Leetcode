class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> s;
        vector<int> ans;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }

            if (s.empty())
                ans.push_back(0);
            else
                ans.push_back(s.top() - i);

            s.push(i);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};