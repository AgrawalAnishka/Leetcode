class Solution {
public:
    int ans = 0;
    vector<bool> vis;

    vector<vector<pair<int, int>>> adj;
    void dfs(int node) {
        if (vis[node]) {
            return;
        }
        vis[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            if (vis[adj[node][i].first]==true)
                continue;
            if (adj[node][i].second == 1) {
                ans++;
            }
            dfs(adj[node][i].first);
        }
        // vis[node] =false;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vis.resize(n + 1, false);
        adj.resize(n + 1);
        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back({connections[i][1], 1});

            adj[connections[i][1]].push_back({connections[i][0], 0});
        }
        dfs(0);
        return ans;
    }
};