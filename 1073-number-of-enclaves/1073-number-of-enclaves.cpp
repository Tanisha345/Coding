void dfs(int i, int j, int n, int m, vector<vector<int>> &visited, vector<vector<int>> &grid){
    grid[i][j]=0;
    int x[4]={-1, 1, 0, 0};
    int y[4]={0, 0, -1, 1};
    for(int k=0; k<4;k++){
        int newx= i+x[k];
        int newy= j+y[k];
        if(newx>=0 && newx<n && newy>=0 && newy<m && visited[newx][newy]==0 && grid[newx][newy]==1){
            visited[newx][newy]=1;
            dfs(newx, newy, n, m, visited, grid);
        }
    }
}


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));

        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && visited[i][0]==0){
                visited[i][0]=1;
                dfs(i, 0, n, m, visited, grid);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 && visited[i][m-1]==0){
                visited[i][m-1]=1;
                dfs(i, m-1, n, m, visited, grid);
            }
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && visited[0][j]==0){
                visited[0][j]=1;
                dfs(0, j, n, m, visited, grid);
            }
        }

        for(int j=0;j<m;j++){
            if(grid[n-1][j]==1 && visited[n-1][j]==0){
                visited[n-1][j]=1;
                dfs(n-1, j, n, m, visited, grid);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};