class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long findKthSmallest(vector<int>& nums, int k) {
        int n = nums.size();

        long long s = *min_element(nums.begin(), nums.end());
        long long e = 1LL * *max_element(nums.begin(), nums.end()) * k;
        long long ans = -1;

        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long ctr = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long L = 1;
                int bits = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;
                        L = lcm(L, nums[i]);

                        if (L > mid)
                            break;
                    }
                }

                if (L > mid)
                    continue;

                if (bits % 2)
                    ctr += mid / L;
                else
                    ctr -= mid / L;
            }

            // AFTER calculating complete inclusion-exclusion
            if (ctr >= k) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};