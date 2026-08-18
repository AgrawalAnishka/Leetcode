class Solution {
public:
    bool isPossible(vector<int>& nums, long long h, long long t) {
        long long ctr = 0;
        for (int i = 0; i < nums.size(); i++) {
            ctr += (nums[i] ) / h;
            if ((nums[i] % h) > 0) {
                ctr += 1;
            }
        }
        // cout<<ctr<<" "<<t<<endl;
        if (ctr <= t) {
            return true;
        } else {
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
            maxi = max(maxi, (long long)piles[i]);
        long long s = 1;
        long long e = maxi;
        long long ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isPossible(piles, mid, h)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};