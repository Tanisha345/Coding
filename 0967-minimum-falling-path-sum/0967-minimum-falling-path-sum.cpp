int solve(int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(n==0) return matrix[n][m];
    if(dp[n][m]!=-1) return dp[n][m];
    int left= INT_MAX, right= INT_MAX, up= INT_MAX;
    if(n-1>=0){
        up= matrix[n][m]+ solve(n-1, m, matrix,dp);
        if(m-1>=0) left= matrix[n][m] + solve(n-1, m-1, matrix, dp);
        if(m+1<matrix[n].size()) right= matrix[n][m]+ solve(n-1, m+1, matrix, dp);
    }

    return dp[n][m]=min(left, min(up, right));
}


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i=0;i<m;i++){
            dp[0][i]= matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int left=INT_MAX, right= INT_MAX, up= INT_MAX;
                if(j-1>=0) left= matrix[i][j]+ dp[i-1][j-1];
                up= matrix[i][j]+dp[i-1][j];
                if(j+1<m) right= matrix[i][j]+ dp[i-1][j+1];

                dp[i][j]= min(left, min(right, up));
            }
        }
        int ans= INT_MAX;
        for(int i=0;i<m;i++){
            ans= min(ans, dp[n-1][i]) ;
        }
        return ans;
    }
};