class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     int n=mat.size();
     int m= mat[0].size();
     vector<vector<int>> visited(n, vector<int>(m, 0));
     vector<vector<int>> ans(n, vector<int> (m, 0));

     queue<pair<pair<int, int>, int>> q;

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                visited[i][j]=1;
                q.push({{i, j}, 0});
            }
        }
     }

int x[4]={-1, 1, 0, 0};
int y[4]= { 0, 0, -1, 1};

     while(!q.empty()){
        auto [cord, dist]=q.front();
        q.pop();
       int oldx= cord.first;
int oldy= cord.second;
        for(int k=0;k<4;k++){
            int newx= oldx+x[k];
            int newy=oldy+y[k];

            if(newx>=0 && newx<n && newy>=0 && newy<m && visited[newx][newy]==0){
                ans[newx][newy]= dist+1;
                visited[newx][newy]=1;
                q.push({{newx, newy}, dist+1});
            }
        }
        
     }

     return ans;   
    }
};