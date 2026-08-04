class Solution {
public:

vector<vector<bool>> vis;
void dfs(vector<vector<char>>& grid , int r , int c){
 
    if(vis[r][c]) return  ;
    vis[r][c] = true;
    int row[4] = {0 ,0,  1, -1};
    int col[4] = {1 , -1, 0, 0};
    for(int i =0 ;i < 4; i ++){
        int nr = r+row[i];
        int nc= c+col[i];
        if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == '1'){

        dfs(grid , nr , nc);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int ans =0 ;
        vis.assign(grid.size() , vector<bool> (grid[0].size() ,  false));
        for(int i  =0 ;i < grid.size() ; i++){
            for(int j  = 0 ; j< grid[i].size() ; j++){
                if(!vis[i][j] && grid[i][j] == '1' ) {
                    ans++;
                    dfs(grid , i , j);
                }
            }
        }
        return ans ;
    }
};