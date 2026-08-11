class Solution {
public:
    int stoneGameVI(vector<int>& numsA, vector<int>& numsB) {
        int n = numsA.size();

        vector<pair<int, int>> stones;

        for(int i = 0; i < n; i++) {
            stones.push_back({
                numsA[i] + numsB[i],
                i
            });
        }

        sort(stones.rbegin(), stones.rend());

        int alice = 0;
        int bob = 0;

        for(int i = 0; i < n; i++) {
            int ind = stones[i].second;

            if(i % 2 == 0)
                alice += numsA[ind];
            else
                bob += numsB[ind];
        }

        if(alice > bob) return 1;
        if(alice < bob) return -1;
        return 0;
    }
};