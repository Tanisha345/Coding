void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &visited){
    board[i][j]='#';
    int x[4]={-1, 1, 0, 0};
    int y[4]={0, 0, -1, 1};

    for(int k=0;k<4;k++){
        if(i+x[k]>=0 && i+x[k]<board.size() && j+y[k]>=0 && j+y[k]<board[0].size() && board[i+x[k]][j+y[k]]=='O' && visited[i+x[k]][j+y[k]]==0){
            visited[i+x[k]][j+y[k]]=1;
            dfs(i+x[k], j+y[k], board, visited);
        }
    }
}


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        
            for(int j=0;j<m;j++){
                if(board[0][j]=='O' && visited[0][j]==0){
                    visited[0][j]=1;
                    dfs(0, j, board, visited);
                }
            }
            for(int j=0;j<m;j++){
                if(board[n-1][j]=='O' && visited[n-1][j]==0){
                    visited[n-1][j]=1;
                    dfs(n-1, j, board, visited);
                }
            }


        for(int i=0;i<n;i++){
          
                if(board[i][0]=='O' && visited[i][0]==0){
                    visited[i][0]=1;
                    dfs(i, 0, board, visited);
                }
        }

        for(int i=0;i<n;i++){
          
                if(board[i][m-1]=='O' && visited[i][m-1]==0){
                    visited[i][m-1]=1;
                    dfs(i, m-1, board, visited);
                }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#')
                board[i][j]='O';
                else
                board[i][j]='X';
            }
        }
    }
};