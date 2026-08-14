class Solution {
public:
    int diameter = 1;
    vector<vector<int>> adj;
     int solve(string &  s, int & start) {
        if(adj[start].empty()) return 1 ;
      
        priority_queue <int, vector<int>,
            greater<int> > pq;
        for (int i = 0; i < adj[start].size(); i++) {
            int temp = solve(s , adj[start][i]);
            if(s[start]==s[adj[start][i]]) continue;
            
            pq.push(temp);
            if(pq.size()>2){
                pq.pop();
            }
           
        }
        int a =0;
        if(!pq.empty()){

         a = pq.top();
         pq.pop();
        }
        int b= 0;
        if(!pq.empty()){

       
         b = pq.top();
        pq.pop();
        }
        diameter = max(diameter,  a+b+1);
        return max(a, b)+1; 
    }
    int longestPath(vector<int>& parent, string s) {
        adj.resize(parent.size() + 1);
        int start = -1;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == -1)
                start = i;
            else{

            adj[parent[i]].push_back(i );
            }
        }
        solve(s, start);
        return diameter;
    }
};