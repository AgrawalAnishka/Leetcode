class Solution {
public:
    vector<vector<long long>> dis;

    void solve() {
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dis[i][k] == LLONG_MAX || dis[k][j] == LLONG_MAX)
                        continue;

                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        dis.assign(26, vector<long long>(26, LLONG_MAX));

        for (int i = 0; i < 26; i++)
            dis[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dis[u][v] = min(dis[u][v], (long long)cost[i]);
        }

        solve();

        long long ans = 0;

        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i])
                continue;

            long long x = dis[source[i] - 'a'][target[i] - 'a'];

            if (x == LLONG_MAX)
                return -1;

            ans += x;
        }

        return ans;
    }
};