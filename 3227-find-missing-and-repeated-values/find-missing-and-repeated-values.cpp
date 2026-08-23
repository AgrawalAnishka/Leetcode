class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        vector<int> temp(grid[0].size() * grid.size() , 0);
        for(int i =0 ;i < grid.size() ; i++){
            for(int j =0 ;j < grid[i].size() ; j++){
                temp[grid[i][j]-1]++;
            }
        }
        int miss =0 ;
        int rep = 0 ;
        for(int i =0 ;i < temp.size() ; i++){
            if(temp[i]==0){
                miss=i;

            }
            if(temp[i]==2){
                rep = i;
            }
        }
        return {rep+1, miss+1} ; 
    }
};