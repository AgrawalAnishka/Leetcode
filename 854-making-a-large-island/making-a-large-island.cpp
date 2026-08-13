class Solution {
public:
    vector<int> parent, sz;

    int findParent(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = findParent(parent[x]);
    }

    void uni(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        parent.resize(n * m);
        sz.assign(n * m, 1);

        for (int i = 0; i < n * m; i++)
            parent[i] = i;

        int dr[] = {1, 0};
        int dc[] = {0, 1};

        // Build existing islands
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                if (grid[r][c] == 0)
                    continue;

                int cell = r * m + c;

                for (int k = 0; k < 2; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < n && nc < m &&
                        grid[nr][nc] == 1) {

                        int next = nr * m + nc;
                        uni(cell, next);
                    }
                }
            }
        }

        int ans = 0;

        // Existing maximum island
        for (int i = 0; i < n * m; i++) {
            if (grid[i / m][i % m] == 1)
                ans = max(ans, sz[findParent(i)]);
        }

        // Try changing every 0 to 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                if (grid[r][c] == 1)
                    continue;

                set<int> parents;

                for (int k = 0; k < 4; k++) {

                    int nr = r + (k == 0) - (k == 1);
                    int nc = c + (k == 2) - (k == 3);

                    if (nr >= 0 && nc >= 0 &&
                        nr < n && nc < m &&
                        grid[nr][nc] == 1) {

                        int cell = nr * m + nc;
                        parents.insert(findParent(cell));
                    }
                }

                int cur = 1;

                for (int p : parents)
                    cur += sz[p];

                ans = max(ans, cur);
            }
        }

        return ans;
    }
};