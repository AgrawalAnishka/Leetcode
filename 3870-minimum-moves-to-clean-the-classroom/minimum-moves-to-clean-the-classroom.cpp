class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
       queue<vector<int>> q;
        int ctrP = 0;
        map<pair<int, int>, int> mp;
        int fr = 0;
        int fc = 0;
        int k = 0;
        for (int i = 0; i < classroom.size(); i++) {
            for (int j = 0; j < classroom[i].size(); j++) {
                if (classroom[i][j] == 'S') {
                    fr = i;
                    fc = j;
                }
                if (classroom[i][j] == 'L') {
                    mp[{i, j}] = k++;
                    ctrP++;
                }
            }
        }

        q.push({0, fr, fc, energy, 0});

        vector<vector<vector<int>>> best(
            classroom.size(), vector<vector<int>>(classroom[0].size(),
                                                  vector<int>(1 << ctrP, -1)));
        vector<vector<int>> vis(classroom.size() + 1,
                                vector<int>(classroom[0].size() + 1, false));
        while (!q.empty()) {
            vector<int> top = q.front();
            q.pop();

            int oper = top[0];
            int r = top[1];
            int c = top[2];
            int eng = top[3];
            int mask = top[4];

            if (eng < 0 || best[r][c][mask] >= eng) {
                continue;
            }
            best[r][c][mask] = eng;
            if (mask == (1 << ctrP) - 1) {
                return oper;
            }

            int nr[4] = {0, 0, 1, -1};
            int nc[4] = {1, -1, 0, 0};

            for (int i = 0; i < 4; i++) {
                if (r + nr[i] >= 0 && c + nc[i] >= 0 &&
                    r + nr[i] < classroom.size() &&
                    c + nc[i] < classroom[0].size() &&
                    classroom[r + nr[i]][c + nc[i]] != 'X') {
                    int newEnergy = eng - 1;

                  if( newEnergy <= best[r+nr[i]][c+nc[i]][mask]) continue;

                    if (newEnergy < 0)
                        continue;
                    if (classroom[r + nr[i]][c + nc[i]] == 'R') {

                        q.push({oper + 1, r + nr[i], c + nc[i], energy, mask});
                    } else if (classroom[r + nr[i]][c + nc[i]] == 'L') {

                        int id = mp[{r + nr[i], c + nc[i]}];

                        int newmask = mask | 1 << id;
                        q.push(
                            {oper + 1, r + nr[i], c + nc[i], eng - 1, newmask});
                    } else {

                        q.push({oper + 1, r + nr[i], c + nc[i], eng - 1, mask});
                    }
                }
            }
        }
        // if(ctr==0) return ans;
        return -1;
    }
};