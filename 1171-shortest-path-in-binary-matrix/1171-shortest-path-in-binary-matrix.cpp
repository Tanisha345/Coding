class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int distance=0;
        vector<vector<int>> visited(n, vector<int> (m, 0));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        visited[0][0]=1;
        if(grid[0][0]==1) return -1;
        while(!q.empty()){
            auto [dist, coords]= q.front();
            q.pop();
            int i= coords.first;
            int j= coords.second;
            if(i==n-1 && j==m-1) return dist;
            int x[8]={-1, 1, 0, 0, -1, 1, 1, -1};
            int y[8]={0, 0, -1, 1, 1, -1, 1 , -1};

            for(int k=0;k<8;k++){
                int newx= i+x[k];
                int newy= j+y[k];

                if(newx>=0 && newx<n && newy>=0 && newy<m && visited[newx][newy]==0 && grid[newx][newy]==0){
                    visited[newx][newy]=1;
                    q.push({dist+1, {newx, newy}});
                }
            }
        }
        return -1;

    }
};