class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int time=0;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<tuple<int, int, int>> q;
        for(int i=0;i<m ;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i, j, 0});
                    visited[i][j]=1;
                }
            }
        }

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
        while(!q.empty()){
            auto [i, j, t]=q.front();
            q.pop();
            for(int a=0;a<4;a++){
                int newi= i+dx[a];
                int newj= j+ dy[a];
                if(newi>=0 && newi< m && newj>=0 && newj<n && grid[newi][newj]==1 && visited[newi][newj]==0){
                    visited[newi][newj]=1;
                    grid[newi][newj]=2;
                    time=t+1;
                    q.push({newi, newj, time});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && grid[i][j]==1)
                return -1;
            }
        }
        return time;
    }
};