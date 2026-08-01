class Solution {
public:
    bool solve(string& s1, string s, int zA) {
        int cs1 = 0;
        int cs = 0;
        int tzA = zA;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == '1') {
                cs1++;
            }
            if (s[i] == '?') {
                if (tzA > 0) {
                    tzA--;
                } else {
                   cs++;
                }
            }else if (s[i] == '1') {
                cs++;
            }

            if (cs > cs1)
                return false;
        }
        return true;
    }
    vector<bool> transformStr(string s1, vector<string>& strs) {
        int zero = 0;
        int one = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        vector<bool> res;
        for (auto& s : strs) {
            int z = 0;
            int o = 0;

            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '0')
                    z++;
                if (s[i] == '1')
                    o++;
            }
            int q = s.size() - z - o;

            if (zero - z + one - o != q || zero-z<0 ||one-o<0) {
                res.push_back(false);
                continue;
            }

            res.push_back(solve(s1, s, zero - z));
        }
        return res;
    }
};