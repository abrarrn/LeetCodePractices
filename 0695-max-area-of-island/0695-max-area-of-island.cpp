class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return false;
        }
        return true;
    }
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(isValid(i,j,grid)){
            grid[i][j]=0;
            return 1+dfs(i,j-1,grid)+dfs(i-1,j,grid)+dfs(i+1,j,grid)+dfs(i,j+1,grid);
        }else{
            return 0;
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==1){
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};