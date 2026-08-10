class Solution {
public:
    unordered_map<string, bool> mp;
    unordered_map<string , bool> dp;
    int bfs(string begin, string endWord) {

        queue<pair<string, int>> q;

        q.push({begin, 1});
        while (!q.empty()) {
            auto [beginWord, dis] = q.front();
            q.pop();
            if (beginWord == endWord)
                return dis;

            if(dp.find(beginWord)!= dp.end()) {
                continue;
            } 
            dp[beginWord] = dis;
            for (int i = 0; i < beginWord.size(); i++) {

                for (char t = 'a'; t <= 'z'; t++) {
                    if (beginWord[i] == t)
                        continue;
                    string temp = beginWord;
                    temp[i] = t;
                    if (mp[temp] == true) {
                        q.push({temp, dis + 1});
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); i++) {
            mp[wordList[i]] = true;
            
        }
        
        if (mp.find(endWord) == mp.end())
            return 0;
        return bfs(beginWord, endWord);
    }
};