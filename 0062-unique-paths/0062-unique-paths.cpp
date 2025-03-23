int solve(int m, int n, vector<vector<int>> &dp){
    if(m<0 || n<0 ) return 0;
    if(m==0 and n==0) return 1;
    if(dp[m][n]!=-1) return dp[m][n];

    int left= solve(m, n-1, dp);
    int right= solve(m-1, n, dp);
    return dp[m][n]=left+right;
}


class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 1));
        vector<int> dp(n, 1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]= dp[j-1]+dp[j];
            }
        }

        return dp[n-1];
    }
};