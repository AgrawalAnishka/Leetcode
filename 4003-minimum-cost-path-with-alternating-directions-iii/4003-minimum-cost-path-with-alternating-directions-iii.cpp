class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        priority_queue<vector<long long>,
                       vector<vector<long long>>,
                       greater<vector<long long>>> pq;

        dp[0][0][1] = 1;
        pq.push({1, 0, 0, 1});   // {cost,row,col,next parity}

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            long long dis = top[0];
            int i = top[1];
            int j = top[2];
            int action = top[3];

            if (dis > dp[i][j][action]) continue;

            if (i == m - 1 && j == n - 1)
                return dis;

            // -------- WAIT ----------
            long long nd = dis + penalty[i][j];
            if (nd < dp[i][j][1 - action]) {
                dp[i][j][1 - action] = nd;
                pq.push({nd, i, j, 1 - action});
            }

            if (action == 1) {        // odd action

                // Down (valid)
                if (i + 1 < m) {
                    nd = dis + (i + 2) * (j + 1);
                    if (nd < dp[i + 1][j][0]) {
                        dp[i + 1][j][0] = nd;
                        pq.push({nd, i + 1, j, 0});
                    }
                }

                // Right (valid)
                if (j + 1 < n) {
                    nd = dis + (i + 1) * (j + 2);
                    if (nd < dp[i][j + 1][0]) {
                        dp[i][j + 1][0] = nd;
                        pq.push({nd, i, j + 1, 0});
                    }
                }

                // Up (invalid)
                if (i > 0) {
                    nd = dis + i * (j + 1) + penalty[i][j];
                    if (nd < dp[i - 1][j][0]) {
                        dp[i - 1][j][0] = nd;
                        pq.push({nd, i - 1, j, 0});
                    }
                }

                // Left (invalid)
                if (j > 0) {
                    nd = dis + (i + 1) * j + penalty[i][j];
                    if (nd < dp[i][j - 1][0]) {
                        dp[i][j - 1][0] = nd;
                        pq.push({nd, i, j - 1, 0});
                    }
                }

            } else {                  // even action

                // Up (valid)
                if (i > 0) {
                    nd = dis + i * (j + 1);
                    if (nd < dp[i - 1][j][1]) {
                        dp[i - 1][j][1] = nd;
                        pq.push({nd, i - 1, j, 1});
                    }
                }

                // Left (valid)
                if (j > 0) {
                    nd = dis + (i + 1) * j;
                    if (nd < dp[i][j - 1][1]) {
                        dp[i][j - 1][1] = nd;
                        pq.push({nd, i, j - 1, 1});
                    }
                }

                // Down (invalid)
                if (i + 1 < m) {
                    nd = dis + (i + 2) * (j + 1) + penalty[i][j];
                    if (nd < dp[i + 1][j][1]) {
                        dp[i + 1][j][1] = nd;
                        pq.push({nd, i + 1, j, 1});
                    }
                }

                // Right (invalid)
                if (j + 1 < n) {
                    nd = dis + (i + 1) * (j + 2) + penalty[i][j];
                    if (nd < dp[i][j + 1][1]) {
                        dp[i][j + 1][1] = nd;
                        pq.push({nd, i, j + 1, 1});
                    }
                }
            }
        }

        return -1;
    }
};