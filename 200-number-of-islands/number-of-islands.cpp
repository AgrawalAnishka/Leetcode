class Solution {
public:
vector<vector<bool>> vis;
void dfs(int r , int c,vector<vector<char>>& grid  ){
    if(vis[r][c]) return ;
    vis[r][c] = true;
    int row[4] = {0 ,0 ,-1,1};
    int col[4] ={1, -1,0,0};
    for(int i = 0; i <4 ; i++){
        int nr = r+row[i];
        int nc = c+ col[i];

        if(nr>=0 &&nc>=0 && nr <grid.size() && nc<grid[0].size()&&!vis[nr][nc] && grid[nr][nc]=='1'){
            dfs(nr , nc, grid);

        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int ctr =0 ;
        vis.resize(grid.size() +1 , vector<bool>(grid[0].size()+1 , false));
        for(int i =0 ;i <  grid.size() ; i++){
            for(int j  =0 ;j < grid[0].size() ;j++){
                if(!vis[i][j] &&grid[i][j]=='1'){
                    ctr++;
                    dfs(i , j , grid);
                }
            }
        }
        return ctr;
    }
};