class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int> rowFlag(n, 0);
        vector<int> columnFlag(m, 0);
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(matrix[i][j]==0){
                rowFlag[i]=1;
                columnFlag[j]=1;
              }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rowFlag[i]==1 || columnFlag[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
        return;
    }
};