class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp ;

        for(int i  =0 ;i <strs.size() ; i++){
            string cat = strs[i];
            sort(cat.begin() ,  cat.end());
            // if(mp.find(cat)!=mp.end()){
                mp[cat].push_back(strs[i]);
            // }else{
            //     mp[cat].push_bnack
            // }
        }

        vector<vector<string>> ans ; 

        for(auto & it: mp){
            vector<string> output;
            for(auto  & temp :  it.second){
                output.push_back(temp);
            }
            ans.push_back(output);
        }
        return ans ;
    }
};