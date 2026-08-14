class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findparent(parent[node]);
    }

    void unionbyrank(int a, int b) {
        int pa = findparent(a);
        int pb = findparent(b);

        if (pa == pb)
            return;

        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }
        else {
            parent[pb] = pa;
            rank[pa] += rank[pb];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                }
                else {
                    ds.unionbyrank(i, mp[mail]);
                }
            }
        }

        vector<vector<string>> merged(n);

        for (auto it : mp) {

            string mail = it.first;
            int node = it.second;

            int parent = ds.findparent(node);

            merged[parent].push_back(mail);
        }
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (merged[i].empty())
                continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (string mail : merged[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};