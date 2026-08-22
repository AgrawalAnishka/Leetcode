class Solution {
public:

    void dfs(vector<vector<bool>> & vis , int r , int c, int m , int n , vector<vector<int>> & nums){
        if(r>=m || c>=n || r <0 || c<0 || vis[r][c]){
            return ;
        }
        vis[r][c] = true;

        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};

        for(int i  =0 ;i < 4 ; i++){
            int nr = r+row[i];
            int nc = c+col[i];

            if(nr>=0 && nc>=0 && nr < m && nc < n ){
                if(!vis[nr][nc] && nums[nr][nc] >= nums[r][c]){
                    dfs(vis,nr,nc,m,n,nums);
                }
            }
        }
    
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums) {
        int n = nums.size() ;
        int m  = nums[0].size();

        vector<vector<bool>> visP(n+1 , vector<bool> (m+1 , false));
        vector<vector<bool>> visA(n+1 , vector<bool>(m+1 , false));

        for(int i  =0 ;i <  n ; i++){
            if(!visA[i][m-1]){
                dfs(visA, i , m-1 , n , m , nums );
            }
        }


        for(int i  =0 ;i <  n ; i++){
            if(!visP[i][0]){
                dfs(visP, i , 0 , n , m , nums );
            }
        }

        for(int i  =0 ;i < m ; i++){
            if(!visP[0][i]){
                dfs(visP , 0 ,i ,n, m , nums );
            }
        }

        for(int  i =0 ;i <  m ; i++){
            if(!visA[n-1][i]){
                dfs(visA , n-1 , i , n , m , nums);
            }
        }
        vector<vector<int>>   ans;
        for(int i  =0 ;i < n ; i ++){
            for(int  j=0 ; j <  m ; j++){
                if(visA[i][j] && visP[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};