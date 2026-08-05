class Solution {
public:
set<int> s;
    vector<vector<int>> adj ; 
    void dfs(int node){
       
        for(int i  =0 ;i <  adj[node].size();i++){
            if(s.find(adj[node][i]) == s.end()){
                 s.insert(adj[node][i]);
                dfs(adj[node][i]);
            }
          
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
     adj.assign(n + 1, vector<int>()); 
        for(int i = 0 ;i < nums.size() ; i++ ){
           adj[nums[i][0]].push_back(nums[i][1]);
        }
        s.insert(k);

        dfs(k);


       



        for(int i  = 0 ; i<n;i++){
            if(s.find(i)==s.end()){
                for(int t  =0 ;t <adj[i].size() ; t++){
                    if(s.find(adj[i][t])!=s.end()){
                        s.clear();
                        // cout<<adj[i][t]<<" ";
                        // s.erase(adj[i][t]);
                    }
                }
            }
        }


        vector<int> ans ;
        for(int i  =0 ; i<n ; i++){
            if(s.find(i)==s.end()){
                ans.push_back(i);
            }
        }
        return ans;




    }
};