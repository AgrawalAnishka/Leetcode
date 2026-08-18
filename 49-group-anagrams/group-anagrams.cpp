class Solution {
public:
unordered_map<string,vector<string>> mp ;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(auto it:  strs){
            string temp = it;
            sort(temp.begin() , temp.end());
            // if(mp.find(temp)!=mp.end()){
                mp[temp].push_back(it) ; 
            // }
        }
        vector<vector<string>> ans;
        for(auto it :  mp){
            vector<string> output; 
            for(auto   i:it.second){
                output.push_back(i);
            }
            ans.push_back(output);
        }
        return ans;
    }
};