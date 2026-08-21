class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        queue<vector<int>> q;
        vector<int> vis(adj.size() + 1, -1);
        for (int i = 0; i < adj.size(); i++) {
            if (vis[i] != -1)
                continue;
            q.push({i, 0});
            vis[i] = 0;
            while (!q.empty()) {
                vector<int> top = q.front();

                q.pop();

                int node = top[0];
                int color = top[1];
                vis[node] = color;
                for (int i = 0; i < adj[node].size(); i++) {
                    if (vis[adj[node][i]] == -1) {
                        vis[adj[node][i]] = 1 - vis[node];
                        q.push({adj[node][i], vis[adj[node][i]]});
                    } else if (vis[adj[node][i]] == vis[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};